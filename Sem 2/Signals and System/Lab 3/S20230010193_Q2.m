clc;
close all;
clear all;

a = input("enter a: ");
t = -10:1:10;
x = (exp(-a.*t).*heaviside(t+1)) + heaviside(-t-3);

plot(t,x);
grid;