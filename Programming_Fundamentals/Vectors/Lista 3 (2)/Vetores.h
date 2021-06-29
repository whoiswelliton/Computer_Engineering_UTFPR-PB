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
void GerarVetorLim (int Vet[], int Tamanho, int LimInf, int LimSup)
{
    int i;

    srand(time(NULL));

    for(i=0;i<Tamanho;i++)
    {
        Vet[i] = rand() % (LimSup - LimInf) + LimInf;
    }
}
void GerarVetorLim2 (float Vet[], int Tamanho, int LimInf, int LimSup)
{
    int i;

    srand(time(NULL));

    for(i=0;i<Tamanho;i++)
    {
        Vet[i] = rand() % ((LimSup - LimInf) + LimInf) / (float)(rand() % 8 + 1);;
    }
}
void MostrarVetor2 (float Vet[],int Tamanho)
{
    int i;
    for(i=0;i<Tamanho;i++)
    {
        printf("%.2f ",Vet[i]);
    }
}
void GerarVetorChar (char Vet[], int Tam)
{
    int i;
    for(i=0;i<Tam-1;i++)
    {
        Vet[i] = rand() % 26 + 97;
    }
    Vet[i] = '\0';
}
void MostrarVetorChar (char Vet[])
{
    int i=0;
    do
    {
        printf("%c ",Vet[i]);
        i++;
    }while(Vet[i] != '\0');
}
