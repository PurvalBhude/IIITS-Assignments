clc;
close all;
clear all;

x = [3,5,-2,2,4,-7,1];
n=-3:1:3;
stem(n,x,"r","filled");

% %x1[n] = 2x[n-3]
a = 3;
[y,m] = shift(x,n,a);
x1=y*2;
stem(m,x1,"r","filled");

%x2[n] = 2x[-n+3]
a = -3;
[y,m] = shift(x,n,a);
[y,m] = fold(y,m);
x2 = 2*y;
stem(m,x2,"r","filled");

%x3[n] = 2x[2n]
b = 2;
[y,m] = scale(x,n,b);
x3 = 2*y;
stem(m,x3,"r","filled");

%x4 = 2x[4n-3]
a = -3;
[y,m] = shift(x,n,a);
b=4;
[y,m] = scale(x,n,b);
x4 = 2*y;
stem(m,x4,"r","filled");

%x5 = 2e0.5nx[n];
x5 = 2*exp(0.5*n).*x;
stem(n,x5,"r","filled");

%x6 = z[-n]
n6 = -n;
x6 = [1,1,0,0,0,-2,-2];
stem(n6,x6);