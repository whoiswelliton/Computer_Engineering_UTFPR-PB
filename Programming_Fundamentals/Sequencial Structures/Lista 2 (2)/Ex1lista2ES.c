#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"

/*
 Ler dois números reais (ponto flutuante) e apresentar, sem utilizar funções matemáticas prontas:
	a) A subtração do primeiro número pelo segundo, mostrar o resultado com duas casas decimais e com arredondamento
	estatístico.
	b) A divisão do primeiro número pelo sgundo, armazenando somente a parte inteira do número.
	c) A soma dos dois números com o resultado arredondado para o próximo número inteiro.
*/

int main (void)
{
    char Continuar;
    int Num1,Num2,Sub,Div,Soma;

    do
    {
        system("cls");
        printf("________________________________________________________________________________\n");
        printf("Informe o primeiro numero: ");
        scanf("%d",&Num1);
        printf("________________________________________________________________________________\n");
        printf("Informe o segundo numero: ");
        scanf("%d",&Num2);

        system("cls");

        Sub = Num1 - Num2;
        Div = Num1/Num2;
        Soma = Num1 + Num2 + 1;

        printf("\nSubtracao: %d",Sub);
        printf("\nDivisao: %d",Div);
        printf("\nSoma: %d",Soma);

        printf("\nPara Executar Novamente (S/s para sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}

