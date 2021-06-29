#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Vetores.h"

/*
*/
int main (void)
{
    int Matriz[10][2],Vet[10],i,j;

    char Continuar;
    do
    {
        system("cls");

        for(i=0;i<10;i++)
        {
            for(j=0;j<2;j++)
            {
                Matriz[i][j] = rand() % (6+1);
                printf("%4d",Matriz[i][j]);



            }
            Vet[i] = pow(Matriz[i][0],Matriz[i][1]);
            printf("\n");
        }

        MostrarVetor (Vet,10);
        printf("________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
