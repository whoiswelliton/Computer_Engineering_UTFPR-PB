#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"
/*
Gerar aleatoriamente um vetor com 100 elementos que conterá somente valores 0 e 1. Mostrar esse vetor.
Em seguida contar quantos 0s sucessivos o vetor contém, armazenar essa quantidade em outro vetor e mostrá-lo.
Qual seria o tamanho mínimo e máximo desse vetor que armazena as quantidades? Criá-lo para  a tamanho máximo
possível.
Exemplo
Vetorgerado: 00010011111000
VetorQuatidades:323 (os três primeiros zeros,os dois zeros subsequentes e os três zeros no final)
*/
int main (void)
{
    char Continuar;
    int i,VetA[100],VetB[100];

    do
    {
        int Qtd=0,Qtd2=0,j=0;

        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("VETOR A:\n");

        GerarVetor(VetA,100,1);
        MostrarVetor(VetA,100);

        for(i=0;i<100;i++)
        {
            if(VetA[i] == 0)
            {
                while(VetA[i] == 0)
                {
                    Qtd++;
                    i++;
                }
            }
            else if (Qtd >= 2)
            {
                VetB[j] = Qtd;
                Qtd=0;
                j++;
            }
        }

        printf("\n_______________________________________________________________________________\n");
        printf("VETOR B(Zeros Consecutivos):\n");
        MostrarVetor(VetB,j);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}



