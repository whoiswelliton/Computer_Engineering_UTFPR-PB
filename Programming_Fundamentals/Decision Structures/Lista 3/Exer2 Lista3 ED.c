#include <stdio.h>
#include <stdlib.h>
/*
Elaborar um programa para ler o código de um produto e o classificá-lo de acordo com a tabela a seguir:
código
classificação
1
Alimento não-perecível
2 a 4
Alimento perecível
5 e 6
Vestuário
7
Higiene pessoal
8 a 15
Limpeza e utensílios domésticos
Qualquer outro código (negativo ou positivo)
Inválido
*/
int main (void)
{
    int codigo;

    printf("Informe o codigo do produto: ");
    scanf("%d",&codigo);


    if (codigo == 1)
    {
        printf ("Alimento nao-perecivel\n");
    }
    else if ((codigo >= 2) && (codigo <=4))
    {
        printf ("Alimento perecivel\n");
    }
    else if ((codigo >=5) && (codigo <=6))
    {
        printf("Vestuario\n");
    }
    else if (codigo == 7)
    {
        printf("Higiene pessoal\n");
    }
    else if ((codigo >=8) && (codigo <=15))
    {
        printf("Limpeza e utensilios domesticos\n");
    }
    else
    {
        printf("Codigo Invalido\n");
    }

    system("pause");
}
