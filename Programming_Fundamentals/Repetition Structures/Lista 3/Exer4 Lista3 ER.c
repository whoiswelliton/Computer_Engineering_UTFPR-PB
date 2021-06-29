#include <stdio.h>
#include <stdlib.h>
/*
Escreva um algoritmo que gere a série de Fibonacci até o vigésimo termo.
A série de Fibonacci é formada pela seqüência: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ... , etc.
*/
int main (void)
{

    int Atual=1,Ante=1,Proxi;
    int Termo,Cont,Soma=2;
    float Media;

    printf("Informe a quantidade de termos: ");
    scanf("%d",&Termo);
    if (Termo >= 1 && Termo <=2)
    {
        printf("1\t1\t");
    }
    else if (Termo =3)
    {
        printf("1\t1\t");// mostra os  2 primeiros termos.
        for(Cont=3;Cont<=Termo;Cont++)
        {
            Proxi = Atual + Ante;
            Ante = Atual;
            Atual = Proxi;
            printf("%d\t",Proxi);
            Soma = Soma + Proxi;
        }
    }
    if (Termo >0)
    {
        Media = (float)Soma/Termo;
        printf("\nA Media e %.2f\n",Media);
        printf("\1\n");
    }
    system("pause");
}
