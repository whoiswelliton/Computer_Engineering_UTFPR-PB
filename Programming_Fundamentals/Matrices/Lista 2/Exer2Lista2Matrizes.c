#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

/*
*/
int main (void)
{
    char Continuar;
    int Numeros[5][5],i,j,SomaC,SomaL,Coluna[5],Linha[5];

    do
    {

        SomaL=0;
        SomaC=0;
        system("cls");
        srand(time(NULL));
        printf("\n_______________________________________________________________________________\n\n");
        printf("\nMatriz:\n\n");
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                Numeros[i][j] = rand() % (100)+1;

            }
        }

        for(i=0;i<5;i++)
        {
            SomaL=0;
            SomaC=0;

            for(j=0;j<5;j++)
            {
                printf("%4d",Numeros[i][j]);
                SomaL+=Numeros[i][j];
                SomaC+=Numeros[j][i];
            }
            Coluna[i]=SomaC;
            Linha[i]=SomaL;
            printf("\n");
        }
        printf("\nVetor Linha\t");
        MostrarVetor(Linha,5);
        printf("\n");
        printf("Vetor Coluna\t");
        MostrarVetor(Coluna,5);


        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

