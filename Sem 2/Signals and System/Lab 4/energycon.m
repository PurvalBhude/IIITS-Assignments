function [a] = energycon(x,xmin,xmax)
syms t;
a = int((x).^2,t,xmin,xmax);
end

