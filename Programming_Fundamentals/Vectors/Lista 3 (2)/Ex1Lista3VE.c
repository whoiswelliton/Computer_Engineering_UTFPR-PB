#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"
#include "Funcoes.h"
/*
Gerar aleatoriamente um vetor com 11 elementos entre 10 e 20.  Em seguida percorrer o vetor e mostrar a quantidade de
divisores de cada um dos valores armazenados.
Utilizar uma função para mostrar os divisores e contar a quantidade. A função mostra os divisores e devolve a
quantidade de divisores, isto é, o seu retorno é essa quantidade.
Ao final mostrar o número que possui a maior quantidade de divisores e a quantidade.
A figura ao lado exemplifica a execução do programa, utilizá-la como modelo para o programa a ser implementado.
*/
int main (void)
{
    char Continuar;
    int Vet[11],i,retorno;
    do
    {
        int MaisDiv=0;

        printf("\n______________________________________________________________________________\n");
        printf("VETOR:\n");
        GerarVetorLim(Vet,11,10,20);
        MostrarVetor(Vet,11);

        printf("\nDivisores:\n");

        for(i=0;i<11;i++)
        {

            retorno = Qtdivisores1 (Vet[i]);

            if(retorno > MaisDiv)
            {
                MaisDiv = retorno;
            }

            printf("\n");
            printf("O Numero %d tem %d  Divisores = ",Vet[i],retorno);
            mostrardivisores(Vet[i]);
            printf("\n");

        }

        printf("\n\nMaior Quantidade de divisores = %d",MaisDiv);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

