#include <stdio.h>
#include <stdlib.h>

/*Ler um nome e ler um caractere. Contar quantos caracteres o nome possui.
 Verificar se o caractere informado está na string (nome lido). Se estiver,
 mostrar o índice em que o mesmo está armazenado. Considerar a última ocorrência
  do caractere se existir mais de uma. Complementar o exercício considerando a
  primeira concorrência do caractere na string.
*/
int main (void)
{
    float Notas[5][2];
    float Maior,Menor;
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
                    printf("Informe a nota %d do Aluno %d: ",j,i);
                    scanf("%f",&Notas[i][j]);

                }while(Notas[i][j] < 0 || Notas [i][j] > 10);
            }
        }

        Maior = Notas[0][0];
        Menor = Notas[0][0];

        for(i=0;i<5;i++)
        {
            for(j=0;j<2;j++)
            {
                if(Notas[i][j] > Maior)
                {
                    Maior = Notas[i][j];
                }
                else if (Notas[i][j] < Menor)
                {
                    Menor = Notas[i][j];
                }
            }

        }

        printf("\nMaior nota %.1f\n",Maior);
        printf("Menor Nota: %.1f\n",Menor);


        printf("______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
