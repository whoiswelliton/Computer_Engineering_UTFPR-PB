#include <stdio.h>
#include <stdlib.h>
/*
Fazer um programa que imprima os ‘n’ primeiros números pares e não divisíveis por 3. n é informado pelo usuário.
Se o usuário informar um valor negativo transformá-lo em positivo.
*/
int main (void)
{
    int Num,Pares,Cont;

    printf("Informe um numero: ");
    scanf("%d",&Num);
    do
    {
        if(Num <= 0)
        {
            printf("Informe um numero 'POSITIVO' : ");
            scanf("%d",&Num);
        }
    }while(Num <=0);

    printf("Pares nao divisiveis por 3 entre 1 e %d:\n",Num);
    for(Cont=1;Cont<=Num;Cont++)
    {
        if(Cont % 2 == 0 && Cont % 3 != 0)
        {
            printf("³%d³\t",Cont);
        }
    }

    system("pause");
}
