clc;
close all;
clear all;

% t = -1:0.1:2;
% x = -t.*exp(t);
% 
% plot(t,x);

% a=1/3;
% t = a*t;
% plot(t,x);
% grid;

% to = 3;
% t = t-to;
% plot(t,x);
% grid;

% t = -2.*t;
% t = 1.+t;
% plot(t,x);
% 
% y = (5*heaviside(t)) - (2*heaviside(t-1)) - (3*heaviside(t-2));
% plot(t,y);
% grid;
% 
% z = (0.5*((4*heaviside(2*t))-(4*heaviside(2*t)))) + (heaviside(t)) - (2*heaviside(t-1)) + (heaviside(t-2));
% plot(t,z);
% grid;

x = [0,-1,-2,2,2,2,1,0];
n = -3:1:4;
stem(n,x);

% --
n3 = n-10;
x3 = x;
stem(n3,x3);

