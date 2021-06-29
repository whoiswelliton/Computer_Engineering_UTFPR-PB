#include <stdio.h>
#include <stdlib.h>


/*
 Escreva um algoritmo que leia um número e verifique se ele é maior, menor ou igual a 10.
*/
int main (void)
{
    int Num;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("Informe um Numero: ");
        scanf("%d",&Num);

        if(Num < 10)
        {
            printf("\nNumero Menor que 10");
        }
        else if(Num > 10)
        {
            printf("\nNumero Maior Que 10");
        }
        else
        {
            printf("\nNumero igual a 10");
        }

        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
