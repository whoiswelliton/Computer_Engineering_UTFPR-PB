#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Vetores.h"

/*
Gerar aleatoriamente 8 elementos para um vetor A. Construir um vetor B de mesma dimensão com os
elementos de A multiplicados por 2.
*/
int main (void)
{
    char Continuar;
    int VetA[8],VetB[8],Tamanho=8,i;

    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("VETOR A:\n");

        GerarVetor(VetA,Tamanho,100);
        MostrarVetor(VetA,Tamanho);

        printf("\n_______________________________________________________________________________\n");
        printf("VETOR B:\n");

        for(i=0;i<8;i++)
        {
            VetB[i] = VetA[i]*2;
        }

        MostrarVetor(VetB,Tamanho);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
