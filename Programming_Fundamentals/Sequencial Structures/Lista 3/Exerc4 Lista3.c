#include <stdio.h>
#include <stdlib.h>
/*
Fazer um programa que leia um número de até três dígitos, calcule e imprima a soma dos seus dígitos.
 Exemplo: 123 = 1 + 2 + 3 = 6.
*/
int main (void)
{
    long int Num;
    int U,D,C;
    int Soma;

    printf("Informe um númeor com até três digitos: ");
    scanf("%li",&Num);

    C = Num/100;
    D = Num%100/10;
    U = Num%10;
    Soma = C+D+U;

    printf("A Soma dos dígitos %d + %d + %d = %d\n",C,D,U,Soma);

    system("pause");
}
