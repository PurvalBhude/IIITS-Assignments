clc;
close all;
clear all;

%Q2
n0 = -5:1:-1;
x0 = zeros(size(n0));

n1 = 0:1:5;
x1 = -n1 + 10;

n2 = 6:1:8;
x2 = n2;

n3 = 9:1:15;  
x3 = zeros(size(n3));  
n = -5:1:15;
x = [x0, x1, x2, x3];

stem(n, x);