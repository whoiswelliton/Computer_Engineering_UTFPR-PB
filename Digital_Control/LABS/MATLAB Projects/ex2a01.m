%% Controle Digital - PWM
clear;
%% Definição de sinais
%%% Valores obtidos diretamente do gráfico
A = 6 % amplitude da senoide
Ts = 1e-3; % periodo de amostragem
NA = 12; % numero de amostras/ciclo
NC = 1.3; % numero de ciclos
VCC=14;
offset=7;
%%% Valores calculados a partir do gráfico
To = NA*Ts; % periodo fundamental
fo = 1/To; % frequencia fundamental
NT = NA*NC; % numero total de pontos
TT = NT*Ts; % tempo total do gráfico
%%% Geração dos sinais em vetores
t=0:Ts:TT;
x = A*sin(2*pi*fo*t)+offset;
%%% Geração do PWM
for k=1:NT+1
ty(2*k-1)=t(k);
y(2*k-1)=VCC;
ty(2*k)=t(k)+x(k)*Ts/VCC;
y(2*k)=0;
end

%% Geração dos Gráficos
[ts,ys]=stairs(ty,y);
area(ts,ys,'FaceColor',[0.7 0.4 0.4])
hold on
plot(t,x,'r:','Linewidth',2);
stem(t,x,'Color',[0 0.5 0],...
'LineWidth',2,'MarkerFaceColor',[0 0.5 0]);
axis([0 TT min(y)-1 max(y)+1])