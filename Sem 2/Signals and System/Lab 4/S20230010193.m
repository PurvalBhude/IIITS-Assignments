clc;
clear all;
close all;

%% Question 1
% a)
x = [1 0 1 2 3 4 5 6];
n = [-1 0 1 2 3 4 5 6];
stem(n,x)
[m,xe,xo] = components(x,n);
stem(m,xe);
title("even");
stem(m,xo);
title("odd");


% b)
n = -20:20;
u = heaviside(n);
a = heaviside(n+5);
b = heaviside(n-10);
x = exp(0.1*n).*(a-b)
[m,xe,xo] = components(x,n);
plot(m,xe);
title("even");
plot(m,xo);
title("odd");


% c)
n = -10:10;
x = cos((0.1*pi*n)+(pi/4)); 
[m,xe,xo] = components(x,n);
stem(m,xe);
title("even");
stem(m,xo);
title("odd");

% d)
syms t;
t = -5:0.1:10;
a = heaviside(t);
b = heaviside(t-1);
x = cos(2*pi*t).*(a-b)
[n,xe,xo] = components(x,t);
plot(n,xe);
title("even");
plot(t,xo);
title("odd");

% e)
w = pi/10;
yt = 1 + 1.5*cos(1*w*t) - 0.6*cos(4*w*t)
z = 1 + 1.5*cos(1*w*(-1*t)) - 0.6*cos(4*w*(-1*t))
[xe,xo] = components(z);
plot(t,xe);
title("even");
plot(t,xo,'k');
title("odd");

%% Question 2
%a)
syms t;
fprintf("\nquestion a)\n")
x = cos(((pi*t)/2) + (pi/4));
a = energycon(x,-inf,inf);
fprintf("Energy: %d\n",a);
b = powercon(x);
fprintf("Power: %d\n",b);

%b)
syms t;
fprintf("\nquestion b)\n")
x = (1+j)*exp((j*pi*t)/2);
a = energycon(x,0,10);
fprintf("Energy: %d\n",a);
b = powercon(x);
fprintf("Power: %d\n",b);

%c)
syms t;
fprintf("\nquestion c)\n")
x = 1;
a = energycon(x,0,100);
fprintf("Energy: %d\n",a);
b = powercon(x);
fprintf("Power: %d\n",b);

%d)
syms t;
fprintf("\nquestion d)\n")
x = 2*cos((4*t)-(pi/4));
a = energycon(x,0,inf);
fprintf("Energy: %d\n",a);
b = powercon(x);
fprintf("Power: %d\n",b);

