#include <stdio.h>
#include <stdlib.h>
/*
6) Ler um número inteiro.
Se o número lido é par:
a) Obter e mostrar a quantidade de dezenas que esse número possui.
b) Dividir o resto, retiradas as dezenas, por 3 e mostrar somente a parte inteira do resultado
dessa divisão.
c) Somar os dígitos do número lido e mostrar.

Por exemplo:
Informado: 125
Dezenas: 12
Divisão: 5 (o resto) dividido por 3
Parte inteira: 2
Soma dos dígitos de 125: 8 (1+2+5)

Se o número lido é impar, verificar se o mesmo é:
	a) maior que 10, se for mostrar a sua raiz quadrada;
b) menor que 10, mostrar a divisão real (float) do mesmo por 3.
*/
int main (void)
{
    int Num;
    int Dezenas;

    printf("Informe um numero: ");
    scanf("%d",&Num);

    if (Num%2)
    {
        Dezenas = Num/10
    }

    system("pause");
}
