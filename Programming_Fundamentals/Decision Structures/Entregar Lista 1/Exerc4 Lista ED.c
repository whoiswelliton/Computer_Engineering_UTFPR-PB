#include <stdio.h>
#include <stdlib.h>
/*
Ler um número ponto flutuante (float):
a) Se o número lido é menor que 100, separar a parte inteira e a parte decimal e mostrá-las
separadamente.
b) Se o número lido é maior ou igual a 100, obter o resto da divisão desse número por 3 e
mostrar esse resto.
*/

int main (void)
{
    float Num,Decimal;
    int Numi,Resto;

    printf("Informe um numero: ");
    scanf("%f",&Num);

    if (Num < 100)
    {
        Numi = (int)Num;
        Decimal = Num-Numi;
        printf("Inteiro: %d\n Decimal: %f\n",Numi,Decimal);
    }
    else
    {
        Resto= (int)Num % 3;
        printf("O Resto da divisao e: %d\n",Resto);
    }

    system("pause");
}
