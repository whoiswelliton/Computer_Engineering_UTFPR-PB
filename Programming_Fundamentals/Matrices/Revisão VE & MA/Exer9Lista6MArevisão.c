#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

int main (void)
{
    int Matriz[8][8],i,j,k;
    char Continuar;
    do
    {
        system("cls");
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                Matriz[i][j]=rand() % 100;
                printf("%4d",Matriz[i][j]);
            }
            printf("\n");
        }
        k=0;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                Matriz[i][j]=rand() % 100;
                if((i < 0 & i <= 6) & (j > 1 & j <= 7))
                {
                    if(i[k] != 0)
                    {
                        printf("0",Matriz[i][j]);
                    }
                    k++;
                }

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
