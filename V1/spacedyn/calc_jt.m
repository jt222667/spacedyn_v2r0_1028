%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots.
% (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida,
% Tohoku University, Japan.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%	February 4, 1999, Last modification by K.Yoshida
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
% CALC_JT	Translational Jacobians w.r.t. link centroid
%
% CALC_JT    关于链路质心的平移雅可比矩阵

function JJ_t = calc_jt( LP, SV )

global Ez


% Calculation of translational jacobians
JJ_t = zeros(3,LP.num_q*LP.num_q);

% If a Single body,
if LP.num_q == 0
   
   JJ_t = [];

% If a Multi body system,
else
   
   for i = 1 : LP.num_q
      
      j = i;
      
      while ( j > 0 )
         
         A_I_j  = SV.AA(:,j*3-2:j*3);
         
         % Rotational joint
         if LP.J_type(j) == 'R'
            JJ_t(:,(i-1)*LP.num_q+j) = cross( (A_I_j*Ez) , ( SV.RR(:,i)-SV.RR(:,j)-A_I_j*LP.cc(:,j,j) ) );
            
         % Prismatic joint
         else
            JJ_t(:,(i-1)*LP.num_q+j) = A_I_j*Ez ;
            
         end
         
         j = LP.BB(j);
         
      end
      
   end
   
end


%%%EOF
