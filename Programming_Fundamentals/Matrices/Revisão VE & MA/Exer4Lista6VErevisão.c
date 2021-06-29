#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

int main (void)
{
    char Continuar;
    int Vet1[50],Vet2[50],Vet3[100],i,j,k,Indice;

    do
    {
        system("cls");
        Indice=i=j=0;

        printf("\nVetor 1:\n\n");
        VetorLim(Vet1,50,50,0);
        MostrarVetor(Vet1,50);

        printf("\nVetor 2:\n\n");
        VetorLim(Vet2,50,50,0);
        MostrarVetor(Vet2,50);

        for(i=0;i<50;i++)
        {
            Vet3[Indice] = Vet2[i];
            Indice++;
        }
        for(i=0;i<50;i++)
        {
            for(j=0;j<50;j++)
            {
                if(Vet1[i] == Vet2[j])
                {
                    break;
                }
            }
            if(j == 50)//chagamos ate o final do vetor e eo elemento nao esta armazenado. Nao ha elemento igual
            {
                Vet3[Indice] = Vet1[i];
                Indice++;
            }
        }
        printf("________________________________________________________________________________");
        printf("%c          %c          %c          %c Vetor 3 %c          %c          %c          %c \n\n",25,25,25,25,25,25,25,25);
        MostrarVetor(Vet3,Indice);

        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

