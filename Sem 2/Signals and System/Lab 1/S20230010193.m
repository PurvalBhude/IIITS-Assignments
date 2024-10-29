x = [1,2,3,4,5,6,7,8,9,10]
y=x.*x
z = y.*x
w=y+z
plot(x,y,'->k',x,z,'-+b',x,w,'-.m')
xlabel("x values of natural number")
ylabel("natural number include its square and cube")
grid
title("Graph for x,x^2,x^3")
xlim([3,9])