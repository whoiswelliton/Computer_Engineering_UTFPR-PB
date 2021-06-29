#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Gerar um vetor para armazenar 24 elementos (valores) float. Os valores, gerados aleatoriamente,
representam a temperatura medida de um paciente de hora em hora, durante as 24 horas de um dia.
O usuário indica a faixa de valores, por exemplo entre 34 e 42. Em seguida:
a) Contar quantas vezes a temperatura esteve maior ou igual a um determinado número informado
pelo usuário.
b) Informar se o paciente apresentou essa temperatura em horas sucessivas.
c) Identificar a maior tempertura e informar a hora em que a mesma ocorreu.
d) Contar quantas vezes a temperatura aumentou, ou seja, foi de um valor menor para um valor maior.

*/

void GerarVetorLim (float Vet[], int Tamanho, float LimInf, float LimSup)
{
    int i;

    srand(time(NULL));

    for(i=0;i<Tamanho;i++)
    {
        Vet[i] = rand() % (LimSup - LimInf) + LimInf;
    }
}

void MostrarVetor (float Vet[],int Tamanho)
{
    int i;
    for(i=0;i<Tamanho;i++)
    {
        printf("%d ",Vet[i]);
    }
}


int main (void)
{
    int i,maior,igual,sus,M,H,qtd;
    float VetorT[24],Temp;
    char Continuar;
    do
    {
        system("cls");

        printf("\n\nInforme uma Temperatura entre 34 e 42 graus: ");
        scanf("%f",&Temp);

        GerarVetorLim(VetorT,24,34.00,42.00);
        MostrarVetor(VetorT,24);

        printf("\n\n");
        M=34;

        for(i=0;i<24;i++)
        {
            if(VetorT[i] == Temp)
            {
                igual++;
            }
            else if(VetorT[i] > Temp)
            {
                maior++;
            }
            else if(VetorT[i] == Temp && VetorT[i+1] == Temp)
            {
                sus++;
            }
            else if(VetorT[i] > M)
            {
                M = VetorT[i];
                H=i;
            }
            else if(VetorT[i+1] > VetorT[i])
            {
                qtd++;
            }
        }

        printf("\nA temperatura esteve %d vezes igual a %d\n",igual,Temp);
        printf("\nA temperatura esteve %d vezes acima de %d\n",maior,Temp);
        if(sus > 0)
        {
            printf("\nO paciente informou horas com temperatura sucessivas\n");
        }
        printf("\nA maior temperatura registrada foi %d as %d horas\n",M,H);
        printf("\nA temperatura aumentou %d vezes \n",qtd);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
