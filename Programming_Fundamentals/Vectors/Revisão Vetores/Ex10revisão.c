#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
) Gerar uma matriz 100 x 10 que se refere respostas de 10 questões de múltipla
escolha de um teste com 100 alunos. Gerar também um vetor de 10 elementos contendo
o gabarito de respostas. As respostas podem ser a, b, c, d ou e, correspondente as alternativas
 das questões. Comparar as respostas de cada candidato com o gabarito e gerar um vetor com a
 quantidade de acertos de cada candidato. Mostrar o gabarito, a matriz de respostas e os acertos.
Mostrar da seguinte forma:

*/

void GerarVetorLim (int Vet[], int Tamanho, int LimInf, int LimSup)
{
    int i;

    srand(time(NULL));

    for(i=0;i<Tamanho;i++)
    {
        Vet[i] = rand() % (LimSup - LimInf) + LimInf;
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

int main (void)
{
    char Continuar;
    char Matriz[100][10];
    int VetorG[10],i,j,k,qtd;

    do
    {
        system("cls");
        srand(time(NULL));
        printf("\n____________________________________________________________________________\n");
        printf("Gabarito:\n");

        GerarVetorLim(VetorG,10,0,5);
        MostrarVetor(VetorG,10);


        for(i=0;i<100;i++)
        {
            for(j=0;j<10;j++)
            {
                Matriz[i][j] = rand() % (5+1);
            }
        }


        for(i=0;i<100;i++)
        {
            qtd=0;
            for(k=0;k<10;k++)
            {
                if(Matriz[i][j] == VetorG[k])
                {
                    qtd++;
                }
            }
            printf("\n\nAluno %d : %d Acertos",i,qtd);
        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
