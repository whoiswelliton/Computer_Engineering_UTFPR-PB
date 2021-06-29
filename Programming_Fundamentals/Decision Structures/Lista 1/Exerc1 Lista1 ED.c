#include <stdio.h>
/*
Elaborar um algoritmo que lê um número que representa uma senha, verifica se a mesma está correta
ou não, comparando-a com 12345 e informa "Acesso autorizado" ou "Acesso negado", conforme o caso.
*/

int main (void)
{
    int SenhaArmazenada=12345;
    int SenhaInformada;

    printf("Informe a Senha ");
    scanf("%d",&SenhaInformada);

    if(SenhaArmazenada == SenhaInformada)//se verdade
    {
       printf("Acesso Autorizado");
    }
    else// se falso
    {
       printf("Acesso Negado");
    }
}
