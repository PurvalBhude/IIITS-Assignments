clc;
clear all;
close all;

t = 0:0.1:10;
n = 0:1:299;
% % part a
% x = cos(2*pi*t) + ((1/0.23)*cos(200*pi*t)) + ((1/2.5)*cos(10*pi*t));
% plot(t,x);
% grid;
% 
% %part b;
% x = cos((20*pi*n)/256) + cos((200*pi*n)/256);
% stem(n,x);
% grid;
% 
% %part c
% syms t;
% f = sin(pi*t)/(pi*t);
% y = int(f, t, -Inf, Inf);
% 
% %part d
% syms t;
% x = cos(pi*t);
% y = sin(pi*t);
% f = x*y;
% z = int(f,t,0,2);

% %part e
% x = cos(2*pi*n).*(exp(-n));
% plot(n,x);

% %part f
% y = abs(1+(1.5*cos(pi*n))-(0.6*cos(4*pi*t)));
% plot(n,y);

%part g
if (t>=0) && (t<=1)
    x = t;
elseif(t>1) && (t<=2)
        x = -t+2;
else
    x=0;
end
plot(t,x);