#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"
#include "Fatorial.h"

/*
1) Fazer um programa para dado n e p inteiros e maiores que zero,
calcular as combinações de n elementos p a p, isto é n!/(p! * (n-p)!).
Utilizar a função do fatorial para implementar a fórmula.
A função deverá ser incluída com #include <Arquivofuncao.h>
*/
int main (void)
{
    char Continuar;
    int N,P,Comb;
    do
    {
        system("cls");
        do
        {
            printf("Informe o primeiro valor: ");
            scanf("%d",&N);
            printf("Informe o Segundo valor: ");
            scanf("%d",&P);

        }while(N <= 0 && P <= 0);

        if( N - P > 0)
        {
            Comb = Fatorial(N)/(Fatorial(P) * Fatorial(N - P));

            printf("Combinacoes dos elementos: %d\n",Comb);
        }

        Pause();
        printf("\nExecutar novamente (S/s para sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');
}

