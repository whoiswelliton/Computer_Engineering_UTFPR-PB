#include <stdio.h>
#include <stdlib.h>
/*
1) Sabe-se que um número da forma n3 é igual a soma de ‘n’ ímpares consecutivos.
Por exemplo: 13 = 1, 23 = 3+5, 33 = 7+9+11, 43 = 13+15+17+19, ...
Escreva um programa que imprima os ímpares consecutivos cuja soma é igual a n3 para
‘n’ no intervalo de 1 até 10 (inclusive). Mostre da seguinte forma:
1^3 = 1
2^3 = 8
3^3 = 27
*/
int main (void)
{
    int Cont,Cont2,Num,Num2;

    do
    {
        for(Cont=1;Cont<=10;Cont++)
        {
            for(Cont2=1;Cont2<=10;Cont++)
            {
                if(Cont2 == 1)
                {
                    Num=Cont2;
                    Num2=Num;
                }
                else if (Cont2 > 1 && Cont2 <=10)
                {
                    Num=Cont2*Cont2*Cont2;
                    if(Num%2!=0)
                    {

                    }
                }

                printf("%d^3 = %d + %d\n",Cont2,Num,Num2);
            }
        }
        Cont++;


    }while(Cont <= 10);

    system("pause");
}
