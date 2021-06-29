#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char Alimentacao;
    char Transporte;

    printf("Recebe vale alimentacao (S/s/N/n): ");
    scanf("%c",&Alimentacao);
    fflush(stdin);//limpar o buffer do teclado
    printf("Recebe o vale transporte (S/s/N/n): ");
    scanf("%c",&Transporte);

    if((Alimentacao == 'S' && Transporte == 'N') || (Alimentacao == 'N' && Transporte == 'S'))
    {
        printf("Recebe somente vale transpote ou somente vale alimentacao\n");
    }
    else
    {
        printf("Situacao irregular\n");
    }


    system("pause");
}
