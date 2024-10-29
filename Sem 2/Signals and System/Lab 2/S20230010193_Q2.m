clc;
clear all;
close all;

% part a
x = 0;
for i = 1:1:1000
    x = x + (1/(i*i));
end
print1 = "solving equation for a gives output %f\n";
fprintf(print1,x);

% part b
p = input("enter p: ");
w = input("enter w: ");
u = input("enter u: ");
v = input("enter v: ");

y = (p+(w/(u+v))) / (p+(w/(v-u)));

fprintf("Answer for b part is %.3f",y);
