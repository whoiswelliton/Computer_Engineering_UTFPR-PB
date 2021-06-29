#include <stdio.h>
#include <stdlib.h>
/*
Elaborar um programa que leia os limites inferior e superior de um intervalo e imprimir todos os números pares no
intervalo e a soma de todos os valores do intervalo. Imprimir o intervalo do valor maior para o menor. O usuário
pode informar os valores em qualquer ordem, ou seja, não necessariamente primeiro o menor ou o maior.
*/

int main (void)
{
    int Linf,Lsup,Cont,Soma=0,Aux;

    printf("Informe o primeiro valor: ");
    scanf("%d",&Linf);
    printf("Informe o segundo valor: ");
    scanf("%d",&Lsup);

    if (Lsup<Linf)
    {
        Aux=Linf;
        Linf=Lsup;
        Lsup=Aux;

        for (Cont=Lsup;Cont>=Linf;Cont--)
        {
            if(Cont % 2 ==0)
            {
                printf("%d\t",Cont);
            }
            Soma+=Cont;
        }
    }
    printf("O intervalo e de: %d\n",Cont);
    printf("A soma dos valores do intervalo e: %d\n",Soma);


    system("pause");
}
