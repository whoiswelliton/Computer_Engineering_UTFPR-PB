#include <stdio.h>
#include <stdlib.h>
/*
Ler números inteiros informados pelo usuário até ser informado o valor -999.
Dentre os números informados, exceto o -999 que é a condição de saída:
a) contar a quantidade de números menores que 10 e os maiores que 100;
b) contar a quantidade de números ímpares;
c) contar a quantidade de números divisíveis por 10;
d) contar a quantidade de números entre 10 e 100;
e) contar quantas vezes é informado o número 30;
f) contar quantas vezes é informado um número diferente de 10, de 20 e de 30.
*/
int main (void)
{
    int Num;
    int Qtdemenor;
    int Qtdeimpar;
    int Num30;
    int Numdif;
    int Qtdemenor;

    do
    {
        printf("Informe um numero: ");
        scanf("%d",&Num);
        if (Num != -999)
        {
            Soma = Soma + Num;
            Qtde++;
        }
    }while (Num != -999);


    system("pause");
}
