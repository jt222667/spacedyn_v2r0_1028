%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots.
% (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida,
% Tohoku University, Japan.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%	February 4, 1999, Last modification by K.Yoshida
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
% CALC_VEL	Calculate the velocity of each link
%
%   CALC_VEL returns the link velocity in the inertial frame
%            for link 1 to n.
%
% CALC_VEL    递推计算各连杆的速度（质心速度和角速度）
%
%   CALC_VEL 返回第 1 至第 n 连杆在惯性坐标系中的速度。

function SV = calc_vel( LP, SV )

%global BB J_type
%global c0 cc
%global num_q Ez
Ez = [0; 0; 1];       % 初始化 Ez

% If a Single body,
if LP.num_q == 0
   
   SV.vv = zeros(3,21);
   SV.ww = zeros(3,21);
   
% If a Multi body system,
else
   
   % Calculation of velocity vectors vv,ww
   for i = 1 : LP.num_q
      
      % Check the link connection: Is the lower one of this link, 0 ?
      if LP.BB(i) == 0
         
         % Current (i-th) link connects to the 0-th link
         A_I_i = SV.AA(:,i*3-2:i*3);
         
         % Rotational joint
         if LP.J_type(i) == 'R'
            SV.ww(:,i) = SV.w0(:) + A_I_i*Ez*SV.qd(i);
            SV.vv(:,i) = SV.v0(:) ...
               + cross( SV.w0(:),(SV.A0*LP.c0(:,i)) ) ...
               - cross( SV.ww(:,i),(A_I_i*LP.cc(:,i,i)) );
            
         % Prismatic joint
         else
            SV.ww(:,i) = SV.w0(:);
            SV.vv(:,i) = SV.v0(:) ...
               + cross( SV.w0(:),(SV.A0*LP.c0(:,i)) ) ...
               - cross( SV.ww(:,i),(A_I_i*LP.cc(:,i,i)) ) ...
               + cross( SV.ww(:,i),(A_I_i*Ez*SV.q(i)) ) ...
               + A_I_i*Ez*SV.qd(i);
            
         end
         
      % Current (i-th) link doesn't connect to the 0-th link
      else
         
         A_I_BB = SV.AA(:,LP.BB(i)*3-2:LP.BB(i)*3);
         A_I_i  = SV.AA(:,i*3-2:i*3);
         
         % Rotational joint
         if LP.J_type(i) == 'R'
            SV.ww(:,i) = SV.ww(:,LP.BB(i)) + A_I_i*Ez*SV.qd(i);
            SV.vv(:,i) = SV.vv(:,LP.BB(i)) ...
               + cross( SV.ww(:,LP.BB(i)),(A_I_BB*LP.cc(:,LP.BB(i),i)) ) ...
               - cross( SV.ww(:,i),(A_I_i*LP.cc(:,i,i)) );
            
         % Prismatic joint
         else
            SV.ww(:,i) = SV.ww(:,LP.BB(i));
            SV.vv(:,i) = SV.vv(:,LP.BB(i)) ...
               + cross( SV.ww(:,LP.BB(i)),(A_I_BB*LP.cc(:,LP.BB(i),i)) ) ...
               - cross( SV.ww(:,i),(A_I_i*LP.cc(:,i,i)) ) ...
               + cross( SV.ww(:,i),(A_I_i*Ez*SV.q(i)) ) ...
               + A_I_i*Ez*SV.qd(i);
            
         end
         
      end
      
   end
   
end


%%%EOF
