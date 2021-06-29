#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"
#include "Funcoes.h"
/*
(DESAFIO) Gerar aleatoriamente dois vetores com 10 elementos menores que 100 do tipo float. Os valores devem ser float
aleatório, isto é, não deve ser utilizado um divisor fixo (por exemplo, rand() % 101 / 0.123). Criar outros dois vetores
 numéricos, em um deles armazenar os valores menores que 50 e em outros os maiores que 50. Mostrar os vetores gerados.
*/
int main (void)
{
    char Continuar;
    float VetA[10],VetB[10],VetC[10],VetD[10];
    do
    {
        int i,j=0;
        system("cls");
        printf("\n______________________________________________________________________________\n");
        printf("VETOR A:\n");
        GerarVetorLim2(VetA,10,0.123,100);
        MostrarVetor2(VetA,10);
        printf("\n______________________________________________________________________________\n");
        printf("VETOR B:\n");
        GerarVetorLim2(VetB,10,0.123,101);
        MostrarVetor2(VetB,10);

        for(i=0;i<10;i++)
        {
            if(VetA[i] < 50)
            {
                VetC[j] = VetA[i];
            }
            j++;
        }
        j=0;
        for(i=0;i<10;i++)
        {
            if(VetB[i] > 50)
            {
                VetD[j] = VetB[i];
            }
            j++;
        }

        printf("\n______________________________________________________________________________\n");
        printf("VETOR C:\n");
        MostrarVetor2(VetC,10);
        printf("\n______________________________________________________________________________\n");
        printf("VETOR D:\n");
        MostrarVetor2(VetD,10);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}



