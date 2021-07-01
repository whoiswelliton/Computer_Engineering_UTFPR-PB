% Define domain
dx = 0.001;
L = pi;
x = (-1+dx:dx:1)*L;
n = length(x); nquart = floor(n/4);
% Define hat function
f = 0*x;
f(nquart:2*nquart) = 4*(1:nquart+1)/n;
f(2*nquart+1:3*nquart) = 1-4*(0:nquart-1)/n;
plot(x,f,'-k','LineWidth',1.5), hold on
% Compute Fourier series
CC = jet(20);
A0 = sum(f.*ones(size(x)))*dx;
fFS = A0/2;
for k=1:20
A(k) = sum(f.*cos(pi*k*x/L))*dx; % Inner product
B(k) = sum(f.*sin(pi*k*x/L))*dx;
fFS = fFS + A(k)*cos(k*pi*x/L) + B(k)*sin(k*pi*x/L);
plot(x,fFS,'-','Color',CC(k,:),'LineWidth',1.2)
end