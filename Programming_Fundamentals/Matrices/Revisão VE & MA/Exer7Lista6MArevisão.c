#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

int main (void)
{
    int Matriz[5][5],i,j;
    char Continuar;

    do
    {
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                Matriz[i][j] = rand() % 20;
                printf("%4d",Matriz[i][j]);
            }
            printf("\n");

        }



        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

