clc;
close all;
clear all;

% %Q1
% n = -10:1:10;
% 
% r2 = n.*unit(n-2);
% 
% r1 = n.*unit(n+1);
% 
% r = n.*unit(n);
% 
% u4 = unit(n-4);
% 
% x = (3.*r2) - (6.*r1) + (3.*r) - (4.*u4);
% 
% stem(n,x,"r");
% 
% 
% %Q2
% n0 = -5:1:-1;
% x0 = zeros(size(n0));
% 
% n1 = 0:1:5;
% x1 = -n1 + 10;
% 
% n2 = 6:1:8;
% x2 = n2;
% 
% n3 = 9:1:15;  
% x3 = zeros(size(n3));  
% n = -5:1:15;
% x = [x0, x1, x2, x3];
% 
% stem(n, x);


% Q3
% n = -10:10;
 
% % a)
% x1 = ((1/4).^(-n)).*(unit(n+1)-unit(n-4));
% x2 = n.*unit(n);
% y = x1.*x2;
% stem(n,y,"filled");

% %b)
% x1 = ((1/4).^(-n)).*(unit(n)-unit(-n-4));
% x2 = 2.*(unit(n+2) - unit(n-3));
% y = x1.*x2;
% stem(n,y,"filled");

% %c)
% x1 = exp(-n.*pi).*unit(n);
% h = n==3;
% y = x1 + h;
% stem(n,y,"filled");

% %d)
% t1 = -10:1:-1;
% x1 = -unit(-t1);
% 
% t2 = 1:1:10;
% x2 = exp(-t2.*pi).*unit(t2);
% 
% x = [x1,0,x2];
% t = -10:1:10;
% 
% h = (t.*unit(t-3)) + 2;
% 
% y = x+h;
% 
% plot(t,y,"r");

 
% %e)
% t=-10:10;
% delta = t==0;
% 
% y = (2*t + 1) + ((-t+3).*(unit(t-2)-unit(t-3))) + delta;
% plot(t,y);