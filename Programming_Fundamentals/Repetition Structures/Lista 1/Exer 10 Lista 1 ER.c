#include <stdio.h>
#include <stdlib.h>
/*
Escrever um programa, que leia valores inteiros até ser lido o valor -99. Após finalizada a leitura
imprimir a média dos valores lidos.
*/
int main (void)
{
    int Num;
    int Soma=0;
    int Qtde=0;
    float Media;


    do
    {
       printf("Informe um numero: ");
       scanf("%d",&Num);
       if(Num != -99)
       {
            Soma = Soma + Num;
            Qtde++;
       }

    }
    while (Num!=-99);

    if(Qtde != -99);
    {
        Media = (float) Soma/Qtde;
        printf("A Media dos valores  e %.2f\n",Media);
    }

    system("pause");
}
