#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"
/*
Gerar aleatoriamente 10 elementos para um vetor. Desse vetor, calcular e mostrar:
a) A soma de elementos armazenados nesse vetor que são inferiores a 100;
b) A quantidade de elementos armazenados nesse vetor que são iguais a 100;
c) A média dos elementos armazenados nesse vetor que são superiores a 100. Validar para não realizar uma divisão por zero.
*/
int main (void)
{
    char Continuar;
    int i,Vet[10];
    float Media;

    do
    {
        int Soma=0,Soma2=0,Qtd=0,Qtd2=0;

        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("VETOR A:\n");

        GerarVetor(Vet,10,500);
        MostrarVetor(Vet,10);

        for(i=0;i<10;i++)
        {
            if(Vet[i] < 100)
            {
                Soma = Soma + Vet[i];
            }
            else if(Vet[i] == 100)
            {
               Qtd++;
            }
            else if(Vet[i] > 100)
            {
                Soma2 = Soma2 + Vet[i];
                Qtd2++;
            }
        }

        Media = (float)Soma2/Qtd2;

        printf("\n_______________________________________________________________________________\n");
        printf("Soma dos elementos menores que 100: %d",Soma);
        printf("\n_______________________________________________________________________________\n");
        printf("Quantidade de Elementos iguais a 100: %d",Qtd);
        printf("\n_______________________________________________________________________________\n");
        printf("Media dos elementos maiores que 100: %.2f",Media);


        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}



