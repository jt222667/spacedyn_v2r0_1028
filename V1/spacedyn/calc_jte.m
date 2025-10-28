%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots.
% (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida,
% Tohoku University, Japan.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%	February 4, 1998, Last modification by K.Yoshida
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
% CALC_JTE	Translational Jacobians w.r.t.
%           for the point specified by connection vector 'joints.'
%
% CALC_JTE    关于连接向量'joints.'指定点的平移雅可比矩阵

function JJ_te = calc_jte(LP, SV, joints)

%global J_type Qe
%global cc ce
%global num_q 
global Ez

% Check number of joint
n = length(joints);

% If a Single body,
if LP.num_q == 0
   
   JJ_te = [];

% If a Multi body system,
else
   
   % Calculation of Joint Position
   [ POS_j, ORI_j ] = f_kin_j( LP, SV, joints );
   
   % Calculation of Effector Position
   [ POS_e, ORI_e ] = f_kin_e( LP, SV, joints );
   
   JJ_te = [];
   
   for i = 1 : 1 : n
      
      A_I_i = SV.AA(:,joints(i)*3-2:joints(i)*3);
      
      % Rotational joint
      if LP.J_type(joints(i)) == 'R'
         
         temp = cross( (A_I_i*Ez) , ( POS_e - POS_j(:,i) ) );
         JJ_te = [ JJ_te temp ];
         
      % Prismatic joint
      else
         
         JJ_te = [ JJ_te A_I_i*Ez ];
         
      end
      
   end
   
end


%%%EOF
