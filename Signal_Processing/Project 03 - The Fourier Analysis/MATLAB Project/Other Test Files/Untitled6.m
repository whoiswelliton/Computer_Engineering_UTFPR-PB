input = load('dados.mat');                                                   
stem(-300:1:299,input.x,'LineStyle','none','MarkerEdgeColor','blue');
title('Sinal de Entrada Amostrado');
ylabel('x[n]');xlabel('n');

FS = 18000;                                      % Frequência de Amostragem              
T = 1/FS;                                                % Período do Sinal
L = length(input.x);                               % Quantidade de Amostras
N = L/2; %300                                        % Amostras por Período
t = -N:1:N-1;                               %Invervalo onde variar a Função
f = FS*(0:(N/2))/N;


CK = zeros(1,N);
n=[0:N-1];
x = 90 + 180*sin(2*pi*60*n/18000) + 60*sin(2*pi*180*n/18000) + 30*sin(2*pi*300*n/18000);
k=[0:N-1];
WN=exp(-1i*2*pi/N);
nk = n'*k;
WNnk=WN.^nk;
CK = x*WNnk;
%zera valores muito próximos à zero
ind=abs(CK)<10e-10;
CK(ind)=0;
Modulo=abs(CK);
Fase=angle(CK);

L=0:length(x)-1;

figure
subplot(211)
stem(L,abs(CK))
figure
subplot(212)
stem(L,angle(CK))

