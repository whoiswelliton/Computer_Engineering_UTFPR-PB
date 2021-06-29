#include <stdio.h>
#include <stdlib.h>
/*
O custo ao consumidor de um carro novo é a soma do custo de fábrica com a percentagem do distribuidor
e a percentagem dos impostos (ambas aplicadas sobre o custo de fábrica). Supondo que a percentagem do
distribuidor é de 12% e os impostos são de 45%. Escrever um algoritmo para, a partir do custo de
fábrica do carro, calcular e mostrar o custo ao consumidor. Ao invés de usar valor fixo, solicitar
para o usuário informar os valores para os percentuais.
*/
int main (void)
{
    float Imposto, PCon;
    float CFab,CCon;

    printf("Informe o valor do custo de fábrica: ");
    scanf("%f",&CFab);
    printf("Informe o valor do Imposto: ");
    scanf("%f",&Imposto);
    printf("Informe o valor do Percentual do Consumidor: ");
    scanf("%f",&PCon);

    CCon = (CFab*Imposto/100)+ (CFab*PCon/100) + CFab;

    printf("O Custo Ao Consumidor é: %.2f\n",CCon);

    system("pause");
}
