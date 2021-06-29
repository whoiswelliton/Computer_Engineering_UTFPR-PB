#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"
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
    int Comprimento,Largura,Altura,Volume;
    char Continuar;

    do
    {
        system("cls");

        printf("________________________________________________________________________________\n");
        printf("Qual a altura da caixa? ");
        scanf("%d",&Altura);
        printf("________________________________________________________________________________\n");
        printf("Qual a Largura da caixa? ");
        scanf("%d",&Largura);
        printf("________________________________________________________________________________\n");
        printf("Qual o Comprimento da caixa? ");
        scanf("%d",&Comprimento);

        Volume = Largura*Altura*Comprimento;

        system("cls");

        printf("________________________________________________________________________________\n");
        printf("O Volume Total %c %d",130,Volume);
        printf("\n________________________________________________________________________________\n");


        printf("Para Executar o Programa Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 'S' || Continuar == 's');

    Pause();
}
