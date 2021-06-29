#include <stdio.h>
#include <stdlib.h>
/*
Apresentar a soma de todos os números divisíveis por 4 entre 40 e 200 e a média dos ímpares e não divisíveis por 5 desse intervalo.
*/
int main (void)
{
    int Cont,Impares=0,SomaImpares=0,Soma=0;
    float Media;

    for(Cont=4;Cont<=200;Cont++)
    {
        if(Cont % 4 ==0)
        {
            Soma=Cont+Cont;
            printf("%d\t",Cont);
        }
        if(Cont % 2 != 0 && Cont % 5 != 0)
        {
            Impares++;
            SomaImpares=SomaImpares + Cont;
        }
    }
    if(Impares > 0)
    {
        Media = (float)Cont / Impares;
        printf("Media dos impares ao divisiveis por 5: %.2f \n\n",Media);
    }
    printf("Soma dos divisiveis por 4: %d \n\n",Soma);

    system("pause");

}
