%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots.
% (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida,
% Tohoku University, Japan.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   version 1 // Oct 4, 1999, Last modification by K.Yoshida
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
% CALC_ACC 	Calculate the accelation of links
%
%   CALC_ACC returns the accelation in the Inertia frame
%   for link 1 to n.
%
%
% CALC_ACC     递推计算各连杆的速度（质心速度和角速度）
%
%   CALC_ACC 返回第 1 至 n 号连杆在惯性坐标系中的加速度

function SV = calc_acc( LP, SV )

Ez = [0; 0; 1];       % 初始化 Ez


% If Single body
if LP.num_q == 0
   
   SV.vd = zeros(3,21);
   SV.wd = zeros(3,21);
   
% If Multi body system
else
   
   % Calcuration of coordinate transfromation matrices
   A_I_0 = SV.A0;
   
   % Calculation of acceletion vectors vd,wd
   for i = 1 : LP.num_q
      
      % Check the link connection: Is the lower one of this link, 0 ?
      if LP.BB(i) == 0
         
         % If the i-th link connects with 0-th link
         A_I_i = SV.AA(:,i*3-2:i*3);
         
         % Rotational joint
         if LP.J_type(i) == 'R'
            SV.wd(:,i) = SV.wd0(:) ...
               + cross(SV.ww(:,i),(A_I_i*Ez*SV.qd(i))) ...
               + A_I_i*Ez*SV.qdd(i);
            SV.vd(:,i) = SV.vd0(:) ...
               + cross( SV.wd0(:),(A_I_0*LP.c0(:,i)) ) ...
               + cross( SV.w0(:),cross(SV.w0(:),(A_I_0*LP.c0(:,i))) )  ...
               - cross( SV.wd(:,i),(A_I_i*LP.cc(:,i,i)) ) ...
               - cross( SV.ww(:,i), cross(SV.ww(:,i),(A_I_i*LP.cc(:,i,i))) );
            
         % Prismatic joint
         else
            SV.wd(:,i) = SV.wd0(:);
            SV.vd(:,i) = SV.vd0(:) ...
               + cross( SV.wd0(:),(A_I_0*LP.c0(:,i)) ) ...
               + cross( SV.w0(:),cross(SV.w0(:),(A_I_0*LP.c0(:,i))) ) ...
               + cross( SV.wd(:,i),(A_I_i*Ez*SV.q(i)) ) ...
               + cross( SV.ww(:,i),cross(SV.ww(:,i),(A_I_i*Ez*SV.q(i))) ) ...
               + 2*cross(SV.ww(:,i),(A_I_i*Ez*SV.qd(i))) + (A_I_i*Ez*SV.qdd(i)) ...
               - cross( SV.wd(:,i),(A_I_i*LP.cc(:,i,i)) ) ...
               - cross( SV.ww(:,i),cross(SV.ww(:,i),(A_I_i*LP.cc(:,i,i))) ) ;
            
         end
         
         
      % Current (i-th) link doesn't have connection with the 0-th link
      else
         A_I_BB = SV.AA(:,LP.BB(i)*3-2:LP.BB(i)*3);
         A_I_i  = SV.AA(:,i*3-2:i*3);
         
         % Rotational joint
         if LP.J_type(i) == 'R'
            SV.wd(:,i) = SV.wd(:,LP.BB(i)) ...
               + cross( SV.ww(:,i),(A_I_i*Ez*SV.qd(i)) ) + (A_I_i*Ez*SV.qdd(i));
            SV.vd(:,i) = SV.vd(:,LP.BB(i)) ...
               + cross( SV.wd(:,LP.BB(i)),(A_I_BB*LP.cc(:,LP.BB(i),i)) ) ...
               + cross( SV.ww(:,LP.BB(i)),cross(SV.ww(:,LP.BB(i)),(A_I_BB*LP.cc(:,LP.BB(i),i))) ) ...
               - cross( SV.wd(:,i),(A_I_i*LP.cc(:,i,i)) ) ...
               - cross( SV.ww(:,i),cross(SV.ww(:,i),(A_I_i*LP.cc(:,i,i))) );
         
         % Prismatic joint
         else
            SV.wd(:,i) = SV.wd(:,LP.BB(i));
            SV.vd(:,i) = SV.vd(:,LP.BB(i)) ...
               + cross( SV.wd(:,LP.BB(i)),(A_I_BB*LP.cc(:,LP.BB(i),i)) ) ...
               + cross( SV.ww(:,LP.BB(i)),cross(SV.ww(:,LP.BB(i)),(A_I_BB*LP.cc(:,LP.BB(i),i))) ) ...
               + cross( SV.wd(:,i),(A_I_i*Ez*SV.q(i)) ) ...
               + cross( SV.ww(:,i),cross(SV.ww(:,i),(A_I_i*Ez*SV.q(i))) ) ...
               + 2*cross( SV.ww(:,i),(A_I_i*Ez*SV.qd(i)) ) + (A_I_i*Ez*SV.qdd(i)) ...
               - cross( SV.wd(:,i),(A_I_i*LP.cc(:,i,i)) ) ...
               - cross( SV.ww(:,i),cross(SV.ww(:,i),(A_I_i*LP.cc(:,i,i))) );
            
         end
         
      end
      
   end
   
end


%%%EOF
