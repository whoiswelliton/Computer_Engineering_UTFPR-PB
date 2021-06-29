#include <stdio.h>
#include <stdlib.h>
/*
Número perfeito é aquele cuja soma de seus divisores, exceto ele próprio,
é igual ao número. Por exemplo: 6 é perfeito porque 1 + 2 + 3 = 6.
Desenvolva um programa que leia um número e verifique se o mesmo é perfeito.
 Prosseguir a leitura enquanto informado um valor maior que zero.
*/
int main (void)
{
    int Num,Cont,Qdiv,Divi;

    printf("Informe um numero: ");
    scanf("%d",&Num);


    for(Cont=1;Cont<=Num;Cont++)//percorrer o intervalo de 1 até o num
    {
        Qdiv=0;
        for(Divi=2;Divi<=Cont;Divi++)//acumular os divisores
        {
            if(Cont % Divi == 0)
            {
                Qdiv=Qdiv + Divi;
            }
        }
        if(Qdiv == Cont)//verificar se a soma dos ivisores é igual ao numero testado
        {
            printf("%d \t",Cont);
        }
    }


    system("pause");
}

