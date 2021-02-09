function ypp= derivada2(f,x0)
h=1e-5;
ypp=(f(x0+h)+f(x0-h)-2*f(x0))/(h^2);
end