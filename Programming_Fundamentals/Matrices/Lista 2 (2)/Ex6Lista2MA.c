#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

/*
Gerar uma matriz 10 x 2  com valores menores que 6. A primeira linha é a base e a segunda o expoente.
 Utilizando a função potência, gerar um vetor que armazena a potência obtida a partir dos valores desses
 dois vetores. A função potência será utilizada para calcular o potência (base elevada a um expoente)
  e não para gerar o vetor. O valor obtido do cálculo será armazenado no vetor. Mostrar como no exemplo:
VetA[0] = 3 e VetB [0] = 3 resultará 27 (3 elevado a 3)
Mostrar o vetor potência conforme o exemplo:
3 ^ 3 = 27
*/
int main (void)
{
    int i,j,k;
    int Martiz[10][2],Vet;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");

        for(i=0;i<10;i++)
        {
            for(j=0;j<2;j++)
            {
                Matriz[i][j] = rand % 7;
            }
        }

        for(i=0;i<j;i++)
        {
            Vet[k]
            k++;
        }


        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
