clc;
clear all;
close all;

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

