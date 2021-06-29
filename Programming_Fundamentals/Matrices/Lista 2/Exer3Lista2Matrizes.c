#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

int main (void)
{
    char Continuar;
    int Matriz[5][5],i,j;

    do
    {
        system("cls");
        srand(time(NULL));

        printf("\n_______________________________________________________________________________\n\n");
        printf("\nMatriz Before:\n\n");
        for(i=0;i<5;i++)
        {
            printf("\n");
            for(j=0;j<5;j++)
            {
                Matriz[i][j] = rand() % (100 + 1);
                printf("%4d",Matriz[i][j]);
            }
        }
        printf("\n");
        printf("\nMatriz After:\n");
        for(i=0;i<5;i++)
        {

            printf("\n");
            for(j=0;j<5;j++)
            {

                if(i == j)
                {
                    Matriz[i][j]= 1;

                }
                else if(i != j)
                {
                    Matriz[i][j]= 0;
                }
                 printf("%4d",Matriz[i][j]);
            }


        }




        printf("\n\nPara executar Novamente (S/s para sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');
}
