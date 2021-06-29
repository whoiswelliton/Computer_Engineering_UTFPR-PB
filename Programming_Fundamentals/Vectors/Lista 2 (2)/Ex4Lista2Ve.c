#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"
/*
Gerar aleatoriamente dois vetores A e B com n elementos. O usuário informa a quantidade de elementos dos
vetores. Validar para que seja informada uma quantidade positiva de elementos. Mostrar os elementos desses
vetores. Construir um vetor C, em que cada elemento de C será 1, quando o elemento de A for maior que o
respectivo elemento em B; 0, quando o elemento de A for igual ao respectivo elemento em B; e -1 quando o
elemento de A for menor que o respectivo elemento em B. Mostrar os elementos desse vetor C.
*/
int main (void)
{
    char Continuar;
    int i,j,qtd;
    do
    {

        do
        {
            system("cls");
            printf("\n_______________________________________________________________________________\n");
            printf("Informe o numero de elementos para os Vetores A e B: \n");
            scanf("%d",&qtd);

        }while(qtd <= 0);

        int VetA[qtd],VetB[qtd],VetC[qtd];

        printf("\n_______________________________________________________________________________\n");
        printf("VETOR A:\n");
        GerarVetor(VetA,qtd,100);
        MostrarVetor(VetA,qtd);
        printf("\n_______________________________________________________________________________\n");
        printf("VETOR B:\n");
        GerarVetor(VetB,qtd,101);
        MostrarVetor(VetB,qtd);

        printf("\n_______________________________________________________________________________\n");
        printf("VETOR C:\n");

        for(i=0;i<qtd;i++)
        {
            for(j=0;j<qtd;j++)
            {
                if(i == j)
                {
                    if(VetA[i] == VetB[j])
                    {
                        printf("1  ");
                    }
                    else if(VetA[i] != VetB[j])
                    {
                        printf("-1  ");
                    }
                }

            }
        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}


