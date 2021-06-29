#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"

/*
Escreva um algoritmo que converta um valor temperatura de graus Fahrenheit para graus Celsius,
cuja fórmula de conversão é: (graus Fahrenheit – 32) * (5/9).
*/

int main (void)
{
    int Cel,Far;
    char Continuar;

    do
    {
        system("cls");

        printf("________________________________________________________________________________\n");
        printf("Informe a Tempuratura em Fahrenheit: ");
        scanf("%d",&Far);
        printf("________________________________________________________________________________\n");
        system("cls");

        Cel = (Far – 32) * (5/9);

        printf("________________________________________________________________________________\n");
        printf("\nO Resustado em graus Celsius %c: %d",130,Cel);
        printf("\n________________________________________________________________________________\n");

        printf("\nPara Executar Novamente (S/s par asim): ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
