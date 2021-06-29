#include <stdio.h>
#include <stdlib.h>
/*
Ler um número. Verificar se o número informado possui a unidade ou a dezena igual a 5.
 Informar “o número possui unidade e/ou dezena 5” ou “o número não possui unidade e
 dezena 5”, conforme o caso. Continuar a leitura enquanto o usuário informar um valor
 diferente de zero. Zero que é a condição de saída não deve ser verificado.
*/
int main (void)
{
    int Num,U,D;

    do
    {
    printf("Informe um numero: ");
    scanf("%d",&Num);
    printf("\n");


    if(Num % 10 == 5)
    {
        printf("Numero possui unidade e/ou dezena 5\n\n");
    }
    else
    {
        printf("Numero nao possui unidade e dezena 5\n\n");
    }
    }while(Num != 0);

    system("pause");
}
