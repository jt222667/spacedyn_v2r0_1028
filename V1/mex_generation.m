t  = zeros(1,1);
T  = zeros(1,1);   
q0 = zeros(1,1);
qf = zeros(1,1);
qr = zeros(21,1);
dqr = zeros(21,1);

codegen -report quintic_trajectory.m -args {t, T, q0, qf} 

codegen -report calculate_dynamics.m -args {qr, dqr}






