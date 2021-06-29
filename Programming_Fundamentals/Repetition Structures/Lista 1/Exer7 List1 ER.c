#include <stdio.h>
#include <stdlib.h>
/*
Ler dois números que representam os limites de um intervalo. Mostrar os ímpares desse intervalo,
em ordem decrescente. O usuário pode informar os valores que representam os limites do intervalo
em ordem crescente ou decrescente.

*/
int main (void)
{
    int LimSup,LimIf,Aux,Cont,SomaPares=0,Qdepares=0;
    float Media;

    printf("Informe o limite inferior do intervalo: ");
    scanf("%d",&LimIf);
    printf("Informe o limite superior do intervalo: ");
    scanf("%d",&LimSup);

    // trocar os valores das variaveis lida, se nescessario
    if (LimSup < LimIf)
    {
        Aux = LimSup;
        LimSup = LimIf;
        LimIf = Aux;
    }

    printf("Valores impares entre %d e %d: \n",LimSup,LimIf);
    for(Cont=LimSup;Cont>=LimIf;Cont--)
    {
        if(Cont%2!=0)
        {
            printf("%d\t",Cont);
        }
        else
        {
            SomaPares=SomaPares+Cont;
            Qdepares++;
        }
    }
    if(Qdepares !=0)
    {
        Media = (float)SomaPares/Qdepares;
        printf("A media e %.2f",Media);
    }

    printf("\n");
    system("pause");
}
