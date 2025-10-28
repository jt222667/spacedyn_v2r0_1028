t  = zeros(1,1);
T  = zeros(1,1);   
q0 = zeros(1,1);
qf = zeros(1,1);
LP = init_LP_1027();
SV = init_SV_1027();
qd = zeros(21,1);

codegen -report quintic_trajectory.m -args {t, T, q0, qf} 
 
codegen -report calc_pos.m -args {LP, SV}

codegen -report calc_aa.m -args {LP, SV}

codegen -report calc_vel.m -args {LP, SV}

codegen -report calc_acc.m -args {LP, SV}

codegen -report calculate_joint_friction.m -args {qd}

codegen -report r_ne.m -args {LP, SV}

codegen -report init_LP_1027.m -args {}
codegen -report init_SV_1027.m -args {}

codegen -report init_LP_1028.m -args {}





