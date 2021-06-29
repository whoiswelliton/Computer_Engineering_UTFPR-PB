#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

int main (void)
{
    char Continuar;
    int Vet[15],VetCopia[15],i,j,Indice;

    do
    {
        system("cls");
        Indice=i=j=0;

        printf("\nVetor :\n\n");

        VetorLim(Vet,15,20,0);

        for(i=0;i<15;i++)
        {
            printf(" Vet[%d] = %d\n",i,Vet[i]);
        }

        for(i=0;i<15;i++)
        {
            for(j=i+1;j<15;j++)
            {
                if(Vet[i] == Vet[j])
                {
                    VetCopia[Indice] = Vet[i];
                    Indice++;
                }
            }
        }
        printf("\n\n");
        MostrarVetor(VetCopia,Indice);



        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

