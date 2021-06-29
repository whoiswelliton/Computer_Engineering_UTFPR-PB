#include <stdio.h>
#include <stdlib.h>
/*
Escrever um programa que leia vários números inteiros. O valor informado 0 indica o final da leitura.
No final imprimir a média dos números múltiplos de 3 informados. O valor que indica o final da leitura
 não deve ser considerado. Validar para que não seja realizada uma divisão por zero.
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
        if(Num !=0 && Num % 3 ==0)
        {
            Soma = Soma + Num;
            Qtde++;
        }

    }
    while(Num != 0);

    if (Qtde != 0)
    {
        Media = (float)Soma /Qtde;
        printf("A Media e : %.2f\n",Media);
    }



    system("pause");
}
