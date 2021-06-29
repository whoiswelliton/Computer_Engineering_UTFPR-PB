#include <stdlib.h>
#include <math.h>
#include <time.h>

//Funcao para gerar um vetor com tamanho e limite de valor passados como parametros

void GerarVetor(int Vetor[], int Tamanho, int Divisor)
{
    int i;

    srand(time(NULL));//Para gerar a semente para a funcao rand.

    for(i=0;i<Tamanho;i++)
    {
        Vetor[i] = rand() % (Divisor + 1);
    }
}

//Funcao para mostrar um vetor com tamanho passado como parametro.
void MostrarVetor(int Vetor[], int Tamanho)
{
    int i;

    for(i=0;i<Tamanho;i++)
    {
        printf("%d\t",Vetor[i]);
    }
}

void VetorLim(int Vet[], int Tam, int Sup, int Inf)
{
    int i;

    for(i=0;i<Tam;i++)
    {
        Vet[i] = rand() % (Sup - Inf + 1) + Inf;
    }
}

int VetorDiv(int Num)
{
    int C,Divisor=0;

    for(C=1;C<=Num;C++)
    {
        if(Num % C == 0)
        {
            Divisor++;

            printf(" %d",C);
        }
    }

    return(Divisor);
}

//Gerar um vetor alfabetico minusculo
void GerarVetorAlfa(char Texto[], int Tam)
{
    int i;

    for(i=0;i<Tam-1;i++)
    {
        Texto[i] = (rand() % 26) + 97;
    }

    //i terá o valor de (Tam-1).

    Texto[i] = '\0';//Para finalizar a string.
}

//Mostrar um vetor alfanumerico
void MostrarVetorAlfa(char Texto[], int Linhas)
{
    int i=0;
    int QtdeMostrados=0;

    while(Texto[i] != '\0')
    {
        printf("%c ",Texto[i]);

        QtdeMostrados++;

        if(QtdeMostrados % Linhas == 0)
        {
            printf("\n");
        }

        i++;
    }
}

//Gerar um vetor com qualquer caractere
void GerarVetorChar(char Texto[], int Tam)
{
    int i=0;

    for(i=0;i<(Tam-1);i++)
    {
        Texto[i] = rand() % 256;
    }

    Texto[i] = '\0';
}
