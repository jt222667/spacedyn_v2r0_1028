% ptpa_mimo_27dof.m
% Template: PTPA-SMC + Adaptive RBFNN + B-type Nussbaum for 27-DOF robot
% IMPORTANT: Replace the dynamics call 'robotDynamics' with your r_ne / inverse dynamics function.
% Author: ChatGPT (整理)
clear; close all; clc;

%% === Simulation settings ===
dt = 0.001;          % sampling time (s) - choose 0.5~1kHz range depending HW
Tsim = 10;           % total sim time (s)
time = 0:dt:Tsim;

n_q = 27;            % total DOF: 6 base + 21 joints
actuated_mask = true(n_q,1); % boolean mask which generalized DOFs are actuated
% If base is not actuated, set actuated_mask(1:6)=false and handle reduced dynamics (see LaTeX)
% For illustration assume joints actuated (if base not actuated, adapt later)
actuated_mask(1:6) = false;  % example: base not directly actuated

%% === Task / reference trajectory ===
% Simple example: joint-space sinusoidal reference for joints (21 joints)
q_ref = @(t) [zeros(6,1); 0.2*sin(0.5*t).*ones(21,1)]; % modify as needed
qd_ref = @(t) [zeros(6,1); 0.2*0.5*cos(0.5*t).*ones(21,1)];
qdd_ref = @(t) [zeros(6,1); -0.2*(0.5)^2*sin(0.5*t).*ones(21,1)];

%% === PTPA parameters ===
Tp = 3.0;            % predefined time (s) - start with 1~5s
eps = 1e-2;          % predefined accuracy for e
rho0 = 1.0;          % initial rho magnitude (tune)
% rho(t): smoothed to avoid singular at t->Tp
rho = @(t) rho_smooth(t, Tp, rho0);

% sliding surface gains
Lambda = diag([zeros(6,1); ones(21,1)*5]);  % example: no sliding for non-actuated base
ks = 30 * ones(n_q,1);   % sliding gain per channel (tune per inertia scale)

%% === RBFNN (split per actuated channel) ===
% Per-channel RBFs (small networks to keep compute low)
rbf_per_channel = 12;  % number of RBF centers per channel (tune)
total_channels = n_q;
Phi = cell(total_channels,1);
centers = cell(total_channels,1);
widths = cell(total_channels,1);
W_hat = cell(total_channels,1);
Gamma = cell(total_channels,1);
W_init = 0.01;

for i=1:total_channels
    % Design input features for channel i: keep small (e.g., qi, qdi, si)
    % For simplicity we use 3-dim input combined into 12 RBFs by grid.
    % In practice, use domain knowledge to pick inputs per channel.
    centers{i} = linspace(-1,1,rbf_per_channel)';     % scalar centers example
    widths{i}  = 0.5 * ones(rbf_per_channel,1);       % uniform widths
    W_hat{i}   = W_init * ones(rbf_per_channel,1);   % initial weights
    Gamma{i}   = eye(rbf_per_channel) * 0.05;        % adaptation rate (tune)
end

% RBF evaluate function handle (vector input optional)
rbf_eval = @(x, centers, widths) exp( - ( (x - centers').^2 ) ./ (2*(widths'.^2) ) );

%% === Nussbaum and adaptive scalars ===
Nussbaum_func = @(psi) psi.^2 .* sin(psi);  % B-type example
psi = zeros(n_q,1);
kappa = ones(n_q,1)*0.1;   % adaptive gain
gamma1 = 0.05; gamma2 = 0.01;  % kappa update

%% === State initialization ===
q = zeros(n_q,1); qd = zeros(n_q,1);
% optionally set initial q to some non-zero
q(7:end) = 0.1;  % small offset for joints
% data logging
Q_log = zeros(length(time), n_q);
QD_log = zeros(length(time), n_q);
Tau_log = zeros(length(time), n_q);
Err_log = zeros(length(time), n_q);
S_log = zeros(length(time), n_q);
V_log = zeros(length(time),1);

%% === Main simulation loop ===
for k = 1:length(time)
    t = time(k);
    % reference
    qd_des = qd_ref(t);
    qdd_des = qdd_ref(t);
    q_des  = q_ref(t);
    
    % errors
    e = q - q_des;
    edot = qd - qd_des;
    s = edot + Lambda * e;    % sliding variable (vector)
    
    % compute sigma (PTPA transform) per-channel or global
    % using per-channel sigma_i = tan(pi/2 * s_i^2 / rho(t)^2)
    rhos = rho(t);
    sigma = tan( (pi/2) * (s.^2) ./ (rhos^2) );
    % to avoid huge numeric, saturate sigma
    sigma = max(min(sigma,1e6), -1e6);
    
    % =================
    % Dynamics call: you must replace this with your r_ne or robotDynamics
    % Expecting the function to provide M, C, G, B (or return dynamics used)
    % Example prototype (user must implement):
    %   [M, C, G, B] = robotDynamics(q, qd);
    % OR return tau_ff = M*qdd_des + ... (feedforward) if available
    % =================
    [M, C, G, B] = robotDynamics_placeholder(q, qd); % <-- REPLACE this
    
    % feedforward / model-based term (optional)
    % If you have desired accel, compute tau_ff = M*qdd_des + C*qd_des + G
    tau_ff = zeros(n_q,1);
    try
        tau_ff = M * qdd_des + C * qd_des + G;
    catch
        % if not available, keep zero and let NN compensate
    end
    
    % ================ Controller per channel ================
    tau = zeros(n_q,1);
    for i=1:n_q
        if ~actuated_mask(i)
            tau(i) = 0;
            continue;
        end
        
        % --- NN estimate: choose input xi for RBF (scalar example: use s_i)
        xi = s(i);  % you can augment to include q(i), qd(i)
        % compute phi (rbf vector) shape [rbf_per_channel x 1]
        phi_i = rbf_eval(xi, centers{i}, widths{i})';  % ensure column
        % NN approx (scalar)
        Wih = W_hat{i};
        nn_est = Wih' * phi_i;
        
        % --- PTPA sliding term (linear)
        u_s = - ks(i) * s(i);
        
        % --- Nussbaum term
        h_sigma = sigma(i);  % could be derivative or any monotone function of sigma
        nu = Nussbaum_func(psi(i));
        u_nuss = - nu * kappa(i) * h_sigma;
        
        % combine
        tau_i = tau_ff(i) + u_s - nn_est + u_nuss;
        tau(i) = tau_i;
    end
    
    % If actuator saturation needed:
    tau = saturate_tau(tau);
    
    % === Integrate robot dynamics to get qdd, then update q, qd (simple Euler) ===
    % Solve for qdd: M*qdd = -C*qd - G + B*tau  (assuming B maps tau->generalized)
    % if B is mapping from actuators to generalized coordinates, we do:
    %   qdd = M^{-1} * ( -C*qd - G + B * tau )
    qdd = M \ ( -C*qd - G + B * tau );
    
    % Euler integration
    qd = qd + qdd * dt;
    q  = q  + qd * dt;
    
    % === Adaptive updates (discrete) ===
    for i=1:n_q
        if ~actuated_mask(i), continue; end
        phi_i = rbf_eval(s(i), centers{i}, widths{i})'; % same phi used above
        % gradient update with leakage and projection
        Wdot = - Gamma{i} * (phi_i * s(i)) ;   % negative sign depends on design; tune
        % add leakage/projection to keep bounded
        W_hat{i} = W_hat{i} + (Wdot(:) * dt);
        % projection (simple clipping)
        maxW = 1e3;
        W_hat{i} = max(min(W_hat{i}, maxW), -maxW);
        % kappa update (discrete Euler)
        kappa(i) = kappa(i) + dt*( gamma1 * abs(s(i)) - gamma2 * kappa(i) );
        % psi update (for Nussbaum)
        psi(i) = psi(i) + dt * ( h_sigma * s(i) );
    end
    
    % === Logging ===
    Q_log(k,:) = q';
    QD_log(k,:) = qd';
    Tau_log(k,:) = tau';
    Err_log(k,:) = e';
    S_log(k,:) = s';
    V_log(k) = 0.5 * (s'*s);
    
end

%% === Plot selected results ===
figure;
plot(time, Err_log(:,7:27)); title('Joint errors (example subset)'); xlabel('t (s)'); ylabel('e (rad)');
legend(arrayfun(@(i) sprintf('e_%d',i), 7:27, 'UniformOutput',false));

figure;
plot(time, Tau_log); title('Control torques'); xlabel('t (s)');

figure;
plot(time, V_log); title('Lyapunov-like value (0.5*s^T*s)'); xlabel('t (s)');

%% === Helper functions ===

function r = rho_smooth(t, Tp, rho0)
    % safe smoothed rho(t) that avoids singular blow-up at t->Tp
    % grows moderately; choose parameters accordingly
    if t < 0.95*Tp
        r = rho0 * (1 + 0.5 * t / Tp);
    elseif t < Tp
        % approach finite but large value smoothly
        r = rho0 * (1 + 0.5 * 0.95 + 5*(t/Tp - 0.95));
    else
        r = rho0 * 5; % freeze after Tp to avoid numeric singularity
    end
end

function [M,C,G,B] = robotDynamics_placeholder(q, qd)
    % Placeholder that returns simple decoupled diag inertia for testing
    n = length(q);
    M = eye(n) * 2.0;
    C = zeros(n);
    G = zeros(n,1);
    B = eye(n); % assume direct actuation mapping
    % Replace this entire function with your real dynamics function (r_ne style)
end

function tau_sat = saturate_tau(tau)
    % actuator saturation for safety
    tau_max = 100;  % N-m or suitable unit
    tau_sat = max(min(tau, tau_max), -tau_max);
end
