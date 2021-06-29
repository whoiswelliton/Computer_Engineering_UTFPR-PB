#include <stdio.h>
#include <stdlib.h>
/*
Elaborar um programa que determine a potência de um número. O usuário informa a base e o expoente e o
programa informa o resultado da base elevada ao expoente. Não podem ser utilizadas funções prontas do C
 para fazer o cálculo da potência, deve ser construído o algoritmo para isso. Por exemplo, o usuário informa
2 para base e 5 para expoente e o programa informa que o resultado é 32. Ou seja, 25 = 2 X 2 X 2 X 2 X 2 = 32.
*/
int main (void)
{
    int Base,Expo,Resul;

    printf("Informe uma Base: ");
    scanf("%d",&Base);
    printf("Informe um Expoente: ");
    scanf("%d",&Expo);
    do
    {
        printf("%d x\t",Base);
        Base=Expo*Base;
        Expo--;
    }while(Expo >= 1);

    printf("o Resultado é: = %d \n",Resul);

    system("pause");
}
