#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"


/*
Gerar uma matriz 5 X 5 com números randômicos, no intervalo de 1 a 100. Em seguida criar dois vetores que
contenham, respectivamente, as somas das linhas e das colunas da matriz. Mostrar os vetores criados.
*/
int main (void)
{
    int Num[5][5],Linha[5],Coluna[5],i,j,SomaC=0,SomaL=0;
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
                Num[i][j] = rand() % (91+10);
                printf("%d\t",Num[i][j]);
            }
            printf("\n");
        }
        printf("\n______________________________________________________________________________\n");


        for(i=0;i<5;i++)
        {
            SomaL=0;
            SomaC=0;

            for(j=0;j<5;j++)
            {
                SomaL = SomaL + Num[i][j];
                SomaC = SomaC + Num[j][i];
            }

            Coluna[i]= SomaC;
            Linha[i]= SomaL;
            printf("\n");
        }

        printf("\nVetor Linha\t");
        MostrarVetor(Linha,5);
        printf("\n\n");
        printf("Vetor Coluna\t");
        MostrarVetor(Coluna,5);




        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

