#include <stdio.h>
#include <stdlib.h>

/*
A pessoa A tem 1,50 metros e cresce 2 centímetros por ano, enquanto a pessoa B tem 1,10 metros e cresce
3 centímetros por ano. Construa um algoritmo que calcule e imprima quantos anos serão necessários para que
B seja maior que A.
*/
int main (void)
{
    int Qtd=0;
    float A =1.50,B =1.10;
    char Continuar;
    do
    {
        system("cls");

        do
        {
            A = A + 0.02;
            B = B + 0.03;
            Qtd++;

        }while(B < A);

        printf("\nForam necessarios %d anos pra os 2 se igualarem",Qtd);

        printf("\n_____________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
