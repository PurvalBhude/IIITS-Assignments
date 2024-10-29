clc;
close all;
clear all;

% Q3
n = -10:10;
 
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