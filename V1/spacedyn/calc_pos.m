%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots.
% (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida,
% Tohoku University, Japan.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%	February 4, 1999, Last modification by K.Yoshida
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
% CALC_POS	Calculate the position vectors of each link
%
%		CALC_POS returns the position vectors RR in the Inertia frame.
%
% CALC_POS    计算每个连杆的位置向量
%
%        CALC_POS 返回惯性坐标系中的位置向量 RR。

function SV = calc_pos( LP, SV )

%global BB J_type
%global c0 cc
%global num_q Ez
Ez = [0; 0; 1];       % 初始化 Ez

% If a Multi body system,

% Calculation of position vectors
for i = 1 : LP.num_q

    A_I_i = SV.AA(:,i*3-2:i*3);

    % Current (i-th) link connects to the 0-th link
    if LP.BB(i) == 0

        % Rotational joint
        if LP.J_type(i) == 'R'
            SV.RR(:,i) = SV.R0(:) + SV.A0*LP.c0(:,i) - A_I_i*LP.cc(:,i,i);

            % Prismatic joint
        else
            SV.RR(:,i) = SV.R0(:) + SV.A0*LP.c0(:,i) + A_I_i*( Ez*SV.q(i)-LP.cc(:,i,i) );

        end

        % Current (i-th) link doesn't connect to the 0-th link
    else

        A_I_BB = SV.AA(:,LP.BB(i)*3-2:LP.BB(i)*3);

        % Rotational joint
        if LP.J_type(i) == 'R'
            SV.RR(:,i) = SV.RR(:,LP.BB(i)) + A_I_BB*LP.cc(:,LP.BB(i),i) - A_I_i*LP.cc(:,i,i);

            % Prismatic joint
        else
            SV.RR(:,i) = SV.RR(:,LP.BB(i)) + A_I_BB*LP.cc(:,LP.BB(i),i) + A_I_i*( Ez*SV.q(i)-LP.cc(:,i,i) );

        end

    end

end




%%%EOF
