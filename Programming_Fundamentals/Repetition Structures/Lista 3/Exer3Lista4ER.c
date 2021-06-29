#include <stdio.h>
#include <stdio.h>
/*
Elaborar um programa que efetue a leitura de valores positivos inteiros até que um valor negativo
seja informado. Ao final devem ser apresentados o maior e o menor valor informados pelo usuário.
O valor negativo, a condição de saída, não deve ser considerado nas comparações para localizar o
 maior e o menor.
*/
int main (void)
{
    int Num,Maior,Menor;

    printf("Informe um numero: ");
    scanf("%d",&Num);
    Maior = Menor = Num;

    while(Num>0)
    {
    printf("Informe um numero: ");
    scanf("%d",&Num);
    if(Num>0)
    {

    if(Num < Menor)
        {
            Menor = Num;
        }
    else if (Num > Maior)
        {
            Maior = Num;
        }
    }
    }
    printf("O Maior e: %d\n",Maior);
    printf("O Menor e: %d\n",Menor);

    system("pause");
}
