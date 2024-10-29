clc;
clear all;
close all;

prompt = "Enter the value in degree Fahrenheit (oF): ";
oF = input(prompt);

oC = (5/9)*(oF-32);

print = "Converting in degree centigrade (oC) it value is %.3f";

fprintf(print,oC);