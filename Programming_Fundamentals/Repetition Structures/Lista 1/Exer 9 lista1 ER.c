#include <stdio.h>
#include <stdlib.h>
/*
Ler uma série de números indicados pelo usuário. O valor -999 indica o final da leitura.
 Encontrar e mostrar o maior e o menor dos valores informados pelo usuário.
*/
int main (void)
{
    int Num=1,Menor,Maior;

    printf("Informe um numero: ");
    scanf("%d",&Num);
    Menor = Maior = Num;

    while(Num != -999)
    {
        printf("Informe um numero: ");
        scanf("%d",&Num);
        if (Num !=-999)
        {
            if(Num > Maior)
            {
                Maior = Num;
            }
            else if (Num < Menor)
            {
                Menor = Num;
            }
        }

    }
    if (Menor != -999)
    {
        printf("O menor e: %d\n",Menor);
        printf("E o  maior e: %d\n",Maior);
    }

    system("pause");
}
