#include <stdio.h>
#include <stdlib.h>
/*
Escrever um programa que receba vários números inteiros. O valor informado -1 indica o final da leitura.
 No final imprimir a quantidade de números múltiplos de 3.
*/
int main (void)
{
    int Num,Qtnum=0;

    do
    {
        printf("Informe um numero: ");
        scanf("%d",&Num);
        if(Num % 3 == 0)
        {
            Qtnum++;
        }
         getchar();

    }while(Num != -1);

    printf(" Total de Multiplos de 3: %d\n",Qtnum);

    system("pause");
}
