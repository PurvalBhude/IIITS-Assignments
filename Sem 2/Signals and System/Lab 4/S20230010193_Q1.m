clc;
clear all;
close all;

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

