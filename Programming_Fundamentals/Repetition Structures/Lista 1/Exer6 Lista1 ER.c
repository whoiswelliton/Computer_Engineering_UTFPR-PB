#include <stdio.h>
#include <stdlib.h>
/*
Ler dois números que representam os limites de um intervalo e ler o incremento.
Mostrar os números desse intervalo de acordo com o incremento indicado. O usuário pode informar
os valores que representam os limites do intervalo em ordem crescente ou decrescente.
*/
int main (void)
{
    int Cont;
    int Num1,Num2;
    int LimSup, LimInf;
    int Incremento;

    printf("Informe o limite inferior do intervalo: ");
    scanf("%d",&Num1);
    printf("Informe o limite Superior do intervalo: ");
    scanf("%d",&Num2);
    printf("Informe o valo do incremento: ");
    scanf("%d",&Incremento);


    if (Num1 > Num2)
    {
        LimSup = Num1;
        LimInf = Num2;
    }
    else
    {
        LimSup = Num2;
        LimInf = Num1;
    }

    for(Cont=LimInf;Cont<=LimSup;Cont=Cont+Incremento)
    {
        printf("%d\t",Cont);
    }
    printf("\n");
    system("pause");
}
