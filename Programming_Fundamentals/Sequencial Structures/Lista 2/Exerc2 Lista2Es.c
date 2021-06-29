#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Ler um número inteiro e imprimir o seu sucessor, sem alterar o conteúdo da variável, e antecessor,
 alterando o conteúdo da variável.
*/

int main (void)
{

    int Num;

    printf("Informe um número: ");
    scanf("%d",&Num);

    printf("%d ==> %d\n",Num, Num+1);

    printf("%d ==>",Num);
    Num= Num - 1;
    printf("%d\n",Num);


    system("pause");
}
