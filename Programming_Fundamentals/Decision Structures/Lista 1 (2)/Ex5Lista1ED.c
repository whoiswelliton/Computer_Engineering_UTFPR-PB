#include <stdio.h>
#include <stdlib.h>

/*
Escreva um algoritmo que leia um número e verifique se ele se encontra fora do intervalo entre 5 e 20.  Mostre uma mensagem se o número está nesse intervalo.
*/
int main (void)
{
    int Num;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe um Numero: ");
        scanf("%d",&Num);

        system("cls");

        if(Num < 5 || Num > 20)
        {
            printf("Esta fora do Intervalo!");
        }
        else
        {
            printf("Esta entre 5 e 20!");

        }

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
