#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"
/*
Gerar aleatoriamente 7 elementos para um vetor A.Construir um vetor B de mesmo tipo,sendo que cada elemento de
B deverá ser o elemento de A correspondente multiplicado por sua posição (ou índice), ou seja, B[i] = A[i] * i.
*/
int main (void)
{
    char Continuar;
    int VetA[7],VetB[7],i;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("VETOR A:\n");

        GerarVetor(VetA,7,100);
        MostrarVetor(VetA,7);

        for(i=0;i<7;i++)
        {
            VetB[i] = VetA[i] * i;
        }

        printf("\n_______________________________________________________________________________\n");
        printf("VETOR B:\n");
        MostrarVetor(VetB,7);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
