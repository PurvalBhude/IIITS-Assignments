function x=ramp(t)
x=zeros(size(t));
x(t>=0)=t(t>=0);
return;