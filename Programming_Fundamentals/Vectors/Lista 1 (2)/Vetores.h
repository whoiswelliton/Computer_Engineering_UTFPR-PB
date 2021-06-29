#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GerarVetor (int Vet[], int Tamanho, int Divisor)
{
    int i;

    srand(time(NULL));

    for(i=0;i<Tamanho;i++)
    {
        Vet[i] = rand() % (Divisor + 1);
    }
}
void MostrarVetor (int Vet[],int Tamanho)
{
    int i;
    for(i=0;i<Tamanho;i++)
    {
        printf("%d ",Vet[i]);
    }
}
