#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

/*
Gerar uma matriz 100 x 10 que se refere respostas de 10 questões de múltipla escolha, referentes a 100 alunos.
 Gerar um vetor de 10 posições contendo o gabarito de respostas que podem ser 1, 2, 3, 4, ou 5. Em seguida
  comparar as respostas de cada candidato com o gabarito e mostrar e mostrar a pontuação correspondente.

*/
int main (void)
{
    int i,j,k,l,m,Qtd;
    int Matriz[100][10],VetG[10],VetR[10];
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("\nGABARITO:\n");
        GerarVetor(VetG,10,5);
        MostrarVetor(VetG,10);


        for(i=0;i<100;i++)
        {
            Qtd=0;
            printf("\nAluno %d ",i);
            GerarVetor(VetR,10,5);
            printf("Respostas: ");
            MostrarVetor(VetR,10);
            for(j=0;j<10;j++)
            {
                if(VetG[j] == VetR[j])
                {
                    Qtd++;
                }
            }
            printf("\nAcertou %d Respostas!\n\n",Qtd);
            getchar();
            system("cls");
        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
