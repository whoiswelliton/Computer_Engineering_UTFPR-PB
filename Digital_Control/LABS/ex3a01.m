%% Controle Digital – rampa+constante
%% Introducao
% Inicialmente limpar as variaveis da memoria
clear;
%% Definição de sinais
%% Valores obtidos diretamente do gráfico
A = 4/8*2; % amplitude da senoide
Ts = 0.1/17; % periodo de amostragem
NA = 16; % numero de amostras/ciclo
NC = 5; % numero de ciclos totais
%% Valores calculados a partir do gráfico
To = NA*Ts; % periodo fundamental
fo = 1/To; % frequencia fundamental
NT = NA*NC; % numero total de pontos
TT = NT*Ts; % tempo total do gráfico
%% Geração de vetores de forma direta
t=Ts:Ts:TT;
kx=0;
%% Geração de vetores em um laco
for k=1:NT
kx=kx+1; % Contador interno no ciclo
    if kx==1
    x(k)=4; % Valor inicial de x
    end
    if (kx>1) % Rampa descrescente
    x(k)=x(k-1)-A/2;
    end
    if (kx>NA/2)
    x(k)=A; % Valor constante
    end
    if (kx==NA)
    kx=0; % Reinicia o ciclo
    end
end

%% Geracao dos graficos
stairs(t,x,'Linewidth',2)
hold on
stem(t,x)

