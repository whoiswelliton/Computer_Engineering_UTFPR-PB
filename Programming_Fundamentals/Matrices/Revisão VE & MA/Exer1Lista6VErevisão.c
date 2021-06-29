#include <stdio.h>
#include <stdlib.h>
#include "tabuada.h"
#include "Vetores.h"

/*
*/
int main (void)
{
    char Continuar;
    int Vet[5],i;

    do
    {
        system("cls");



        printf("\nVetor:\n\n");

        VetorLim(Vet,5,9,0);

        MostrarVetor(Vet,5);

        for(i=0;i<5;i++)
        {
            Tabuada(Vet[i]);
        }




        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
