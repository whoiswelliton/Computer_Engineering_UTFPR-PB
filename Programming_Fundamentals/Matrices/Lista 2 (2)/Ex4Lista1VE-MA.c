#include <stdio.h>
#include <stdlib.h>

/*
Ler duas notas de 5 alunos. Armazená-las em uma matriz. Encontrar a maior e a menor entre as notas armazenadas.
*/
int main (void)
{
    float Notas[5][2],Maior,Menor;
    int i,j;
    char Continuar;

    do
    {
        system("cls");

        for(i=0;i<5;i++)
        {
            for(j=0;j<2;j++)
            {
                do
                {
                    printf("Informe nota %d para aluno %d: ",j,i);
                    scanf("%f",&Notas[i][j]);
                }while(Notas[i][j] < 0 || Notas[i][j] > 10);

            }
        }
        Maior=Notas[0][0];
        Menor=Notas[0][0];

        for(i=0;i<5;i++)
        {
            for(j=0;j<2;j++)
            {
                if(Notas[i][j] > Maior)
                {
                    Maior = Notas[i][j];
                }
                else if(Notas[i][j] < Menor)
                {
                    Menor = Notas[i][j];
                }
            }
        }

        printf("\nMenor nota: %.2f / Maior Nota: %.2f\n",Menor,Maior);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
