#include <stdio.h> //contém printf() e scanf()
/* Escreva um algoritmo que leia o comprimento, a largura
 e a altura de uma caixa retangular e calcule o seu volume,
 cuja fórmula é: Volume = Comprimento * Largura * Altura.
   Entrada:
       Altura
       Comprimento
       Largura
    Processamento:
       Volume = Comprimento * Largura * Altura
    Saída
       Volume
*/

int main (void)
{
    //declarar variáveis
    float Largura;
    float Altura;
    float Comprimento;
    float Volume;

    //entrada
    printf("Informe o valor da largura: ");
    scanf("%f",&Largura);
    printf("Informe o valor da altura: ");
    scanf("%f",&Altura);
    printf("Informe o valor do comprimento: ");
    scanf("%f",&Comprimento);

    //processamento
    Volume = Largura * Comprimento * Altura;

    //saída
    printf("Volunme: %f",Volume);
}
