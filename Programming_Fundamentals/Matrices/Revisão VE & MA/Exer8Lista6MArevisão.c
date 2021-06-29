#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

int main (void)
{
    int Vet[50],Vet2[50],i,j;
    char Continuar;
    do
    {
        system("cls");
        j=0;
        printf("\nVetor 1:\n\n");
        VetorLim(Vet,50,50,0);
        MostrarVetor(Vet,50);

        printf("\nVetor 2:\n\n");
        for(i=0;i<50;i++)
        {
            if(Vet[i] != 0)
            {
                Vet2[j] = Vet[i];
                j++;
            }
        }
        MostrarVetor(Vet2,j);



        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

