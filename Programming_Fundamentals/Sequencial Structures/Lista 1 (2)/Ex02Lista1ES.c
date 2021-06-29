#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"
/*Escreva um algoritmo que leia o valor de uma prestação e da taxa de juros cobrada pelo atraso da prestação. Calcule o valor a ser pago por meio da fórmula:
 Atraso = Prestação + (Prestação * Taxa /100).
     Entrada
         Prestação
         Taxa
     Processamento
         Atraso = Prestação + (Prestação * Taxa /100)
*/
int main (void)
{
    int Prestacao,Juros;
    float Atraso;
    char Continuar;

    do
    {
        system("cls");

        printf("________________________________________________________________________________\n");
        printf("Informe o Valor da Prestação:");
        scanf("%d",&Prestacao);
        printf("________________________________________________________________________________\n");
        printf("Informe a Taxa de juros cobrada:");
        scanf("%d",&Juros);

        Atraso = (float)Prestacao + (Prestacao*Juros/100);

        system("cls");
        printf("________________________________________________________________________________\n");
        printf("Valor Total os juros cobrados %c: %.2f",130,Atraso);
        printf("\n________________________________________________________________________________\n");
        printf("\nPara executar novamente (S/s para sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 'S' || Continuar == 's');
    Pause();
}
