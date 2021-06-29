#include <stdio.h>
#include <stdlib.h>

/*
Ler a quantidade de horas que uma pessoa utiliza por semana para estudar, trabalhar e dormir.
Calcular e mostrar o percentual que as horas utilizadas para essas atividades representam de uma semana.
Por exemplo:
Estudar = 30 horas
Trabalhar = 40 horas
Dormir = 70 horas
Calcular o percentual que cada umas dessas atividades representa considerando o total de horas de uma semana.

*/
int main (void)
{

    int Estudo,Trabalho,Dormir;
    float Total,X,Y,Z;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Quantas horas voce usa para o Estudo: ");
        scanf("%d",&Estudo);
        printf("\n________________________________________________________________________________\n");
        printf("Quantas horas voce usa para o Trabalho: ");
        scanf("%d",&Trabalho);
        printf("\n________________________________________________________________________________\n");
        printf("Quantas horas voce usa para Dormir: ");
        scanf("%d",&Dormir);

        X = (float)(100*Estudo)/168;
        Y = (float)(100*Trabalho)/168;
        Z = (float)(100*Dormir)/168;

        printf("\n Voce utiliza %.2f  da sua semana Estudando.",X);
        printf("\n Voce utiliza %.2f  da sua semana Trabalhando.",Y);
        printf("\n Voce utiliza %.2f  da sua semana Dormindo.\n\n",Z);

        printf("_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
