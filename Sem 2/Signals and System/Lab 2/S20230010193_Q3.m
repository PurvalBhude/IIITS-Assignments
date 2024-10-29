clc;
clear all;
close all;

R = 5;
C = 10
L = 4;
E = 2;
w = 2;

I = E/sqrt((R^2)+((2*pi*w*L)-(1/(2*pi*w*C)))^2);

fprintf("for R = 5,C = 10,L = 4,E = 2,w = 2 calculated I is %.5f",I);