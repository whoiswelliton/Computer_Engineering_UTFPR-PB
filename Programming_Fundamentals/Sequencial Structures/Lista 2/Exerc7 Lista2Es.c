#include <stdio.h>
#include <stdlib.h>
/*
Faça um programa que leia o preço de uma mercadoria com diferença de um mês e calcule a taxa de
inflação (ou deflação) mensal dessa mercadoria.
*/

int main (void)
{
    float MP, MA, Inflacao;

    printf("Informe o valor da mercadoria no Mes Passado: ");
    scanf("%f",&MP);
    printf("Informe o valor da mercadoria no Mes Atual : ");
    scanf("%f",&MA);

    Inflacao=((MP - MA)*100)/MP;

    printf("A taxa de inflacao ou deflacao e de: %.2f%%\n",Inflacao);

    system("pause");
}
