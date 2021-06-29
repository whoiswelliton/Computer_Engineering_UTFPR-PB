#include <stdio.h>
#include <stdlib.h>
/*
Elaborar um algoritmo que lê dois valores, verifica se o primeiro é múltiplo do segundo e escreve a
mensagem ‘São múltiplos’ ou ‘Não são múltiplos’ dependendo da condição. Verificar para que não seja
realizada uma divisão por zero. Nesse caso, informar que não é possível realizar uma divisão por zero.
*/
int main (void)
{
    int Num1,Num2;

    printf("Informe o valor maior: ");
    scanf("%d",&Num1);
    printf("Informe o valor menor: ");
    scanf("%d",&Num2);

    if (Num2 == 0)
    {
        printf("Divisão por zero\n");
    }
    else// é possivel realizar a divisão
    {
        if(Num1 % Num2 == 0)
        {
           printf("%d e multiplo de %d\n",Num1,Num2);
        }
        else
        {
           printf("%d nao e multiplo de %d\n",Num1,Num2);
        }
    }
    system("pause");
}
