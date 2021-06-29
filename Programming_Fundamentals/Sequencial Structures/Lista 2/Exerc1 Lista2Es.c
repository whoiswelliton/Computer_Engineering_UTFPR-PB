#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Contém funçoes matematicas
/*
Ler dois números reais (ponto flutuante) e apresentar:
	a) A subtração do primeiro número pelo segundo com duas casas decimais, com arredondamento estatístico.
	b) O primeiro número com a parte decimal truncada, ou seja, só mostrar a parte inteira.
	c) A soma dos dois números com o resultado arredondado para o próximo número inteiro.
*/

int main (void)
{
    float Num1, Num2;
    float Subtracao;
    int Soma,Primeiro;

    printf("Informe o primeiro valor: ");
    scanf("%f",&Num1);
    printf("Informe o segundo valor: ");
    scanf("%f",&Num2);

    Subtracao = round((Num1 - Num2));
    Primeiro = trunc(Num1); // apanhar somente a parte inteira
    Soma = ceil(Num1 + Num2); //arredondar para o proximo inteiro

    printf("%f - %f ==> %f\n",Num1,Num2,Subtracao);
    printf("%f ==> %d\n",Num1,Primeiro);
    printf("%f + %f ==> %f\n",Num1,Num2,Soma);

    Primeiro = (int)Num1;
    Soma = (Num1 + Num2) + 0.999999;


    printf("\n\n%f - %f ==> %.2f\n",Num1,Num2,Subtracao);
    printf("%f ==> %d\n",Num1,Primeiro);
    printf("%f + %f ==> %d\n",Num1,Num2,Soma);

    system("pause");
}
