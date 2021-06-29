#include <stdio.h>
#include <stdlib.h>

/*
Fazer um programa que leia um número de até três dígitos, calcule e imprima a soma dos seus dígitos.
Exemplo: 123 = 1 + 2 + 3 = 6.
*/
int main (void)
{
    char Continuar;
    float Num,C,D,U,Soma;

    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe um numero inteiro com 3 digitos: ");
        scanf("%f",&Num);

        system("cls");

        C = (int)Num/100;
        D = (int)Num % 100 / 10;
        U = (int)Num % 10;

        Soma = C + D + U;

        printf("\n%.0f = %.0f + %.0f + %.0f = %.0f ",Num,C,D,U,Soma);

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                          Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
