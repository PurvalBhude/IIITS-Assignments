%Q1
clc;
clear all;
close all;

prompt = "Enter the value in degree Fahrenheit (oF): ";
oF = input(prompt);

oC = (5/9)*(oF-32);

print = "Converting in degree centigrade (oC) it value is %.3f";

fprintf(print,oC);

%Q2
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

%Q3
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

%Q4
clc;
clear all;
close all;

t = 0:0.1:10;
n = 0:1:299;
% % part a
% x = cos(2*pi*t) + ((1/0.23)*cos(200*pi*t)) + ((1/2.5)*cos(10*pi*t));
% plot(t,x);
% grid;
% 
% %part b;
% x = cos((20*pi*n)/256) + cos((200*pi*n)/256);
% stem(n,x);
% grid;
% 
% %part c
% syms t;
% f = sin(pi*t)/(pi*t);
% y = int(f, t, -Inf, Inf);
% 
% %part d
% syms t;
% x = cos(pi*t);
% y = sin(pi*t);
% f = x*y;
% z = int(f,t,0,2);

% %part e
% x = cos(2*pi*n).*(exp(-n));
% plot(n,x);

% %part f
% y = abs(1+(1.5*cos(pi*n))-(0.6*cos(4*pi*t)));
% plot(n,y);

% %part g
% if (t>=0) && (t<=1)
%     x = t;
% elseif(t>1) && (t<=2)
%         x = -t+2;
% else
%     x=0;
% end
% plot(t,x);