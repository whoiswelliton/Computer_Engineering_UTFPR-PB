N=100;

x=zeros(1,N);
y=zeros(1,N);
k=0;

for n = 3 : N
    x(n) = 5;
    k = k+1;
    if k>20 x(n) = 0; end
    if k>40 k=0; end
    
    y(n) = (8*y(n-1) - 3*y(n-2) + 4*x(n-1) + x(n-2))/10;
    
    % teste com outros coef% 
    %y(n) = (6*y(n-1) - 1*y(n-2) + 3*x(n-1) + 0.8*x(n-2))/10;
end

%subplot(2,2,1); 
%stem(x)
%subplot(2,2,2);
hold on;
%stem(y)
%subplot(2,2,[3,4]);
hold on;
stem(x);
stem(y);