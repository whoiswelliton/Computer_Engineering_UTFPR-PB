#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

/*
Elaborar uma função para calcular o mdc (maior divisor comum) entre dois números. Os números são lidos na função chamadora e passados
como parâmetro para a função que calcula o mdc. Esta função retorna o mdc para a função chamadora.
*/
int main (void)
{
    int Num1,Num2,Retorno;
    char Continuar;

    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("                              Calculadora de MDC");
        printf("\n_______________________________________________________________________________\n");
        printf("Informe o Primeiro Numero: ");
        scanf("%d",&Num1);
        printf("\n_______________________________________________________________________________\n");
        printf("Informe o Segundo Numero: ");
        scanf("%d",&Num2);

        system("cls");

        Retorno = MDC (Num1,Num2);

        printf("\n_______________________________________________________________________________\n");
        printf("\nO Maior Divisor Comum (MDC) entre os 2 numeros informados %c = %d",130,Retorno);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
