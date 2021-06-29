#include <stdio.h>
#include <stdlib.h>
/*
Elaborar um programa que efetue a leitura sucessiva de valores numéricos e apresente no final a soma
dos valores informados, a média e o total de valores lidos. O programa deve fazer as leituras dos
valores enquanto o usuário estiver fornecendo valores positivos. Ou seja, o programa deve parar
quando o usuário informar um valor negativo e esse valor não deve ser considerado nos cálculos.
*/
int main (void)
{
    int Num,QtdeNum=0,Soma;
    float Media;

    do
    {
        printf("Informe um Numero: ");
        scanf("%d",&Num);
        QtdeNum++;
        Soma+=Num;

    }while(Num > 0);

    Media = Soma/QtdeNum;

    printf("A Media total e de: %f \1 \n",Media);

    system("pause");
}
