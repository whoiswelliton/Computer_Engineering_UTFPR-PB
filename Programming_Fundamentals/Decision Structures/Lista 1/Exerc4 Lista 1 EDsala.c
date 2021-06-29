#include <stdio.h>
#include <stdlib.h>
/* Escreva um algoritmo que leia um número e verifique se ele se encontra no intervalo entre 5 e 20.
Mostre uma mensagem conforme o caso.
*/

int main (void)
{
    int Num;
    printf("Informe um numero: ");
    scanf("%d",&Num);

    if(Num>=5 && Num <=20)
    {
        printf("%d Esta entre 5 e 20\n",Num);
    }
    else// se o resultado do teste em if e falso
    {
        printf("%d nao esta entre 5 e 20\n",Num);
    }

    system("pause");
}
