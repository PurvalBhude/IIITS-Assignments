function x=P(t,T)
x=zeros(size(t));
x(rem(t,T)==0)=1;
end