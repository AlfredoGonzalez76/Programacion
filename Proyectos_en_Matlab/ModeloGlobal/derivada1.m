function yp= derivada1(f,x0)
h=1e-5;
yp=(f(x0+h)-f(x0-h))/(2*h);
end