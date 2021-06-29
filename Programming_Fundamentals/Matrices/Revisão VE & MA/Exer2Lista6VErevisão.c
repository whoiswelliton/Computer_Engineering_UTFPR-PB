#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

int main (void)
{
    char Continuar;
    int Vet1[30],Vet2[30],Vet3[30],i,j,Indice;

    do
    {
        system("cls");
        Indice=i=j=0;

        printf("\nVetor 1:\n\n");

        VetorLim(Vet1,30,50,0);
        MostrarVetor(Vet1,30);

        printf("\nVetor 2:\n\n");

        VetorLim(Vet2,30,50,0);
        MostrarVetor(Vet2,30);

        printf("\nIntersecção dos Vetores:\n\n");

        for(i=0;i<30;i++)
        {
            for(j=0;j<30;j++)
            {
                if(Vet1[i] == Vet2[j])
                {
                    Vet3[Indice] = Vet1[i];
                    Indice++;

                }
            }
        }
        MostrarVetor(Vet3,Indice);



        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
