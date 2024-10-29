clc;
close all;
clear all;

%Q1
n = -10:1:10;

r2 = n.*unit(n-2);

r1 = n.*unit(n+1);

r = n.*unit(n);

u4 = unit(n-4);

x = (3.*r2) - (6.*r1) + (3.*r) - (4.*u4);

stem(n,x,"r");