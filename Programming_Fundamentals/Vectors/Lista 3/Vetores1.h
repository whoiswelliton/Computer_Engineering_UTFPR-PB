#include <stdlib.h>
#include <math.h>
#include <time.h>

// funcao para gerer um vetor com tamanho e limite de valor passados como parametros

void GerarVetor(int Vetor[], int Tamanho, int Divisor)
{
    int i;
    srand(time(NULL));//para gere a semente para a funcao rand
    for(i=0;i<Tamanho;i++)
    {
        Vetor[i] = rand() %(Divisor + 1);
    }

}

//funcao para mostrar um vetor com tamanho passado como parametro
void MostrarVetor (int Vetor[], int Tamanho)
{
    int i;
    for(i=0;i<Tamanho;i++)
    {
        printf("%d\t",Vetor[i]);
    }

}

void VetorLim (int Vetor[],int Tamanho,int LI,int LS)
{
    int i;
    for(i=0;i<Tamanho;i++)
    {
        Vetor[i]=rand()%(LS-LI+1)+LI;
    }

}

