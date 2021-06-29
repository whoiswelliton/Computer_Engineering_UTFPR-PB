#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"
/*
Em uma determinada cidade, sabe-se que, de janeiro a abril de um determinado ano (121 dias), a temperatura ficou entre
a 15° e 40°. Gerar um vetor com valores randômicos nesse intervalo para esse período de tempo. Em seguida, obtenha e mostre:
a) a menor temperatura ocorrida;
b) a maior temperatura ocorrida;
c) a temperatura média;
d) o número de dias em que a temperatura foi inferior à temperatura média.
*/
int main (void)
{
    char Continuar;
    int i,Vet[121];
    float Media;

    do
    {
        system("cls");
        int Maior=15,Menor=40,Soma=0,Qtd=0,Qtd2=0;

        printf("\n_______________________________________________________________________________\n");
        printf("Temperaturas:\n");

        GerarVetorLim(Vet,121,15,40);
        MostrarVetor(Vet,121);

        for(i=0;i<121;i++)
        {
            if(Vet[i] > Maior)
            {
                Maior = Vet[i];
            }
            else if(Vet[i] < Menor)
            {
                Menor = Vet[i];
            }

            Soma = Soma + Vet[i];

            Qtd++;
        }

        Media = (float)Soma/Qtd;

        for(i=0;i<121;i++)
        {
            if(Vet[i] < Media)
            {
                Qtd2++;
            }
        }

        printf("\n_______________________________________________________________________________\n");
        printf("Menor temperatura: %d \n",Menor);
        printf("\n_______________________________________________________________________________\n");
        printf("Maior temperatura: %d \n",Maior);
        printf("\n_______________________________________________________________________________\n");
        printf("Temperatura media: %.2f \n",Media);
        printf("\n_______________________________________________________________________________\n");
        printf("A Temperatura foi menor que a media por %d Dias\n",Qtd2);


        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}




