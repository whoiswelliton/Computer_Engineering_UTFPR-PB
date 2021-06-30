%%Definições iniciais
figure
hold on
T=0.01;
z=tf('z',T);
s=tf('s');
%% F.T. em tempo contínuo
F=(s+3)/(s*(s^2+10*s+100))
impulse(F)
%% Discret. Método Forward
s=(z-1)/T;
F_For=(s+3)/(s*(s^2+10*s+100))
impulse(F_For)
 %% Discret. Método Backward
s=(z-1)/(T*z);
F_Bac=(s+3)/(s*(s^2+10*s+100))
impulse(F_Bac)
 %% Discret. Método Trapezoidal
s=2/T*(z-1)/(z+1);
F_Tra=(s+3)/(s*(s^2+10*s+100))
impulse(F_Tra)
 %% Discret. Método c2d
F_c2d=c2d(F,T);
impulse(F_c2d)
%% Ajustes no gráfico
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend