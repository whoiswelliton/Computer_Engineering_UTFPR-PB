#include <stdio.h>
#include <stdlib.h>
/* Escreva um algoritmo que calcule o valor da conversão em dólares de um valor lido em reais.
 O algoritmo deverá ler o valor da cotação do dólar e a quantidade de reais.
*/

int main (void)
{
    float Dolar, Real;
    float CotaD;

    printf("Informe o valor em Reais: ");
    scanf("%f",&Real);
    printf("Informe o valor da Cotação do Dolar: ");
    scanf("%f",&CotaD);

    Dolar = Real*CotaD;

    printf("O Valor Em Dolares é de: %.2f\n",Dolar);

    system("pause");
}


