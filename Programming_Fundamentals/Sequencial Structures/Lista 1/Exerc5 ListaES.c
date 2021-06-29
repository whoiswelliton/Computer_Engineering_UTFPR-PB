#include <stdio.h>
/* Calcular o salário líquido de uma pessoa. Sobre o salário bruto incidem descontos de 27% de imposto de renda e 10% de INSS.
      Entrada:
         Bruto
         Impostos
      Processamento:
         Líquido = Bruto / Impostos
      Saída
         Impostos
*/

int main (void)

{
    int Bruto;
    int Liquido;
    float Impostos;

    printf("Informe o valor do Salario Bruto: ");
    scanf("%f",&Bruto);
    printf("Informe o valor dos Salario Liquido: ");
    scanf("&2f",&Liquido);

    Impostos = Bruto - Liquido / 37;

    printf("O total de impostos é: %.2f",Impostos);

}




