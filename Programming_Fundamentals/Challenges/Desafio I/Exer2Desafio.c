#include <stdio.h>
#include <stdlib.h>
/*
Fazer um programa que calcule o valor de S com n informado pelo usuário, determinado
pela série: S = (n-1 *n) / 1 + (n-2 * n-1) / 2 + (n-3 * n-2) / 3 + ... (1 * 2) / n-1.
 Para n = 38:
S = (37 * 38) / 1 + (36 * 37) / 2 + (35 * 36) / 3 + ... + (1 * 2) / 37
*/
int main (void)
{
    int Num,Cont,Soma;

    printf("Informe um numero: ");
    scanf("%d",&Num);

    for(Cont=1;Cont<Num;Cont++)
    {
        Soma = Soma+(Num-1 *Num)/Cont;
        Num = Num-1;
    }

    printf("Resultado = %d\n",Soma);

    system("pause");
}
