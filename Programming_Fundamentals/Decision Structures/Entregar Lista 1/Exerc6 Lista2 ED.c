#include <stdio.h>
#include <stdlib.h>
/*Um hotel cobra R$ 80,00 por diária mais uma taxa de serviços de acordo com:
	R$ 5,50 por diária, se o número de diárias for maior que 15;
	R$ 6,00 por diária, se o número de diárias for igual a 15;
	R$ 8,00 por diária, se o número de diárias for menor que 15.
	Fazer um programa para determinar o valor a ser pago pelo cliente. Se informado zero
	ou valor negativo para a quantidade de diárias não realizar o cálculo.
*/
int main (void)
{
    int Diaria;
    float ValorP;

    printf("Informe o numero de diarias: ");
    scanf("%d",&Diaria);

    if (Diaria <= 0)
    {
        printf("Numero invalido");
    }
    else if (Diaria > 15)
    {
        ValorP = (Diaria*80.00) + (Diaria*5.50);
        printf("O Valor a pagar e de: R$%.2f\n",ValorP);
    }
    else if (Diaria < 15)
    {
        ValorP = (Diaria*80.00) + (Diaria*8);
        printf("O Valor a pagar e de: R$%.2f\n",ValorP);
    }
    else
    {
        ValorP = (Diaria*80.00) + (Diaria*6);
        printf("O Valor a pagar e de: R$%.2f\n",ValorP);
    }
    system("pause");
}
