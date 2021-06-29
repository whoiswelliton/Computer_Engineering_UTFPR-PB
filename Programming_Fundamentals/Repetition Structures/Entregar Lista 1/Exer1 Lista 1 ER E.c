#include <stdio.h>
#include <stdlib.h>
/*
Elaborar um programa para mostrar os números pares entre 20 e 100. Fazer a média dos valores desse intervalo que são divisíveis por 5.
*/
int main (void)
{
    int Cont, Num=20;
    float Media;

    printf("Mostrar o conteudo de uma variavel somente declarada\n");
    printf("Num: %d\n",Num);

     for(Cont=1;Cont<=100;Cont+2)
    {
        printf("%d\t",Num);
        Num=Num+2;
    }
    {
        Media = (float)Num/5;
        printf("A media dos valores do intervalo: %.2f\n",Media);
    }

    system("pause");
}
