#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"


/*
Gerar uma matriz 5x5. Mostrar a matriz obtida. Em seguida preencher com 1 a diagonal principal e com 0 os
demais elementos. Mostrar novamente a matriz.
*/
int main (void)
{
    int Matriz[5][5],i,j;
    char Continuar;
    do
    {
        system("cls");
        srand(time(NULL));
        printf("\n____________________________________________________________________________\n");
        printf("MATRIZ:\n");


        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                Matriz[i][j] = rand() % (91+10);
                printf("%d\t",Matriz[i][j]);
            }
            printf("\n");
        }

        printf("\n______________________________________________________________________________\n");
        printf("MATRIZ 2:\n");

        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(i == j)
                {
                    Matriz[i][j] = 1;
                }
                else
                {
                    Matriz[i][j] = 0;
                }
                printf("%d\t",Matriz[i][j]);
            }
            printf("\n");

        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}


