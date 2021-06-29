#include <stdio.h>
#include <stdlib.h>
/*
Elaborar um algoritmo que lê um número que representa uma senha, verifica se a mesma está correta ou não,
 comparando-a com 12345 e informa "Acesso autorizado" ou "Acesso negado", conforme o caso.
*/
int main (void)
{

    int Senha1, Senha2 = 12345;
    char Continuar;

    do
    {
        system("cls");
        printf("\n______________________________________________________________________________\n");
        printf("\nInforme uma Senha: ");
        scanf("%d",&Senha1);
        system("cls");

        if(Senha1 == Senha2)
        {
            printf("\nSenha Correta!");
        }
        else
        {
            printf("\nSenha Incorreta!");
        }

        printf("________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
