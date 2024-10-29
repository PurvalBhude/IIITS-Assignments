% t = 0:0.1:10;
% y = cos(t);
% plot(t,y);

% n=0:0.5:10;
% y=cos(n);
% stem(n,y);

% t=0:0.1:10;
% x = cos((3*pi*t)+(pi/3));
% plot(t,x);
% grid;

% A = 1;
% y = A*(exp(A*t));
% plot(t,y);

t = -2:0.1:5;
x = -3*(exp(0.4*t));
y = 2*(exp(-0.6*t));
plot(x,y);
grid;

t=0:0.1:6*pi;
x = cos(t) + sin(3*t);
plot(t,x);

n = -25:25;
x = (1.1).^n;
stem(n,x);

n = -20:0.05:20;
w = 0.8;
j = 2;
x = cos(w*n) + j*sin(w*n);
plot(n,x);
stem(n,x);
