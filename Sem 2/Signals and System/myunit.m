function x=myunit(t)
x=zeros(size(t));
x(t==0)=1;
end