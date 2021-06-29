#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"
#include "Vetores1.h"

/*
Em uma determinada cidade, sabe-se que, de janeiro a abril de 1976 (121 dias),
a temperatura ficou entre a 15° e 40°. Gere um vetor com valores randômicos nesse intervalo.
 Em seguida, obtenha e mostre:
a) a menor temperatura ocorrida;
b) a maior temperatura ocorrida;
c) a temperatura media;
d) o numero de dias no qual a temperatura foi inferior a temperatura media.
*/
int main (void)
{
    int Maior,Menor,i,LI,LS,Tamanho,Num,Soma=0,QtTem=0,Qtdias=0;
    float Media;
    char Continuar;
    do
    {
        system("cls");
        fflush(stdin);
        Soma=0;
        QtTem=0;
        Qtdias=0;
        LI = 15;
        LS = 40;
        Tamanho=10;

        int Vetor[10];

        VetorLim (Vetor,Tamanho,LI,LS);
        printf("________________________________________________________________________________\n");
        printf("\nTemperaturas: \n\n");

        Maior = Menor = Vetor[0];

        for(i=0;i<10;i++)
        {
            Soma=Soma+Vetor[i];
            QtTem++;

            if(Vetor[i] < Menor)
            {
                Menor = Vetor[i];
            }
            else if(Vetor[i] > Maior)
            {
                Maior = Vetor[i];
            }

            printf("%d\t",Vetor[i]);
        }

        Media = (float)Soma/QtTem;

        for(i=0;i<10;i++)
        {
            if(Vetor[i] < Media)
            {
                Qtdias++;
            }
        }

        printf("\n\nMaior Temperatura: %d\n",Maior);
        printf("\nMenor Temperatura: %d\n",Menor);
        printf("\n\Media das Temperaturas: %.1f\n",Media);
        printf("\nA Temperatura foi inferior a temperatura media em %d Dias\n",Qtdias);
        printf("\n________________________________________________________________________________\n");

        printf("\nExecutar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
