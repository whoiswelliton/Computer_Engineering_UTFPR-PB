#include <stdio.h>
/*Escreva um algoritmo que leia o valor de uma prestação e da taxa de juros cobrada pelo atraso da prestação. Calcule o valor a ser pago por meio da fórmula: Atraso = Prestação + (Prestação * Taxa /100).
     Entrada
         Prestação
         Taxa
     Processamento
         Atraso = Prestação + (Prestação * Taxa /100)
*/

int main(void)
{
   //declarar variáveis
   float Prestacao;
   float Taxa;
   float Atraso;

   //entrada
   printf("Informe o valor da prestação: ");
   scanf("%f",&Prestacao);
   printf("Informe o valor da taxa; (ex.: 10%%)");
   scanf("%f",&Taxa);

   //processamento
   Atraso = Prestacao + (Prestacao * Taxa/ 100);

   //saída
   printf("Prestação com acrécimo R$ %.2f",Atraso);
}
