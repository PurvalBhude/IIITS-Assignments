function [b] = powercon(x)
syms t T;
xmin = -T/2;
xmax = T/2;
z = int(x.^2,t,xmin,xmax);
b = limit((1/T)*z,T,inf);
end