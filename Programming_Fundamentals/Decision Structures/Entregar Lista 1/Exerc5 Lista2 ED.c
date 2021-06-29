#include <stdio.h>
#include <stdlib.h>
/*
Calcular o imposto de renda de uma pessoa de acordo com a seguinte tabela:
	Renda anual
Alíquota*
Dedução**
Até R$ 10000,00
0%
Isento
> R$ 10000,00 e <= R$ 25000,00
10%
R$ 1000,00
Acima de R$ 25000,00
25%
R$ 4750,00
	*Alíquota é o percentual para o cálculo do valor a ser pago.
	**Dedução é o valor deduzido do valor calculado a ser pago.
	Se informado valor negativo não realizar o cálculo e informar o usuário.
	*/
int main (void)
{
    float Imposto,RendaAnual;

    printf("Informe a Renda Anual: ");
    scanf("%f",&RendaAnual);

    if (RendaAnual <= 0)
    {
        printf("Valor Invalido");
    }
    else if (RendaAnual <= 10000)
    {
        printf("Isento");
    }
    else if (RendaAnual > 10000 && RendaAnual < 25000)
    {
        Imposto = (RendaAnual*10/100) - 1000;
        printf("Imposto sera de: %.2f\n",Imposto);
    }
    else
    {
        Imposto = (RendaAnual*25/100) - 4750;
        printf("Imposto sera de: %.2f\n",Imposto);
    }

    system("pause");
}
