#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"

// Escreva um algoritmo que converta um valor de temperatura de graus Celsius para graus Fahrenheit, cuja fórmula de conversão é: (9 * graus Celsius + 160) /5.

int main (void)
{
    int Cel,Far;
    char Continuar;

    do
    {
        system("cls");

        printf("________________________________________________________________________________\n");
        printf("Informe a Tempuratura em Celsius: ");
        scanf("%d",&Cel);
        printf("________________________________________________________________________________\n");
        system("cls");

        Far = (9 * Cel + 160) /5;

        printf("________________________________________________________________________________\n");
        printf("\nO Resustado em graus Fahrenheit %c: %d",130,Far);
        printf("\n________________________________________________________________________________\n");

        printf("\nPara Executar Novamente (S/s par asim): ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
