#include <stdio.h>
#include <stdlib.h>
/*
Mostrar os termos da série de Fibonacci até o termo n. Sendo n informado pelo usuário.
Por exemplo, se informado 7 para n,  apresentar:
1	1	2	3	5	8	13
*/
int main (void)
{
    int Termo;
    int Cont;
    int Proximo;
    int Anterior=1;
    int Atual=1;
    int Soma = 0;
    float Media;

    printf("Informe a quantidade de termos: ");
    scanf("%d",&Termo);

    if(Termo >= 1 && Termo <= 2)
    {
        printf("1\t1\t");
        Soma = 1 + 1;// 1 e 1
    }
    else if(Termo >= 3)
    {
        printf("1\t1\t");
        for(Cont=3;Cont<=Termo;Cont++)
        {
            Proximo = Atual + Anterior;
            Anterior = Atual;
            Atual = Proximo;
            printf("%d\t",Proximo);
            Soma = Soma + Proximo;
        }
    }

    if (Termo > 0)
    {
        Media = (float)Soma/Termo;
        printf("\A media e %.2f\n",Media);
    }

    system("pause");
}


