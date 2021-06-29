#include <stdio.h>
#include <stdlib.h>

/*
Elaborar um algoritmo que leia uma letra. Se informado ‘F’ ou ‘f’ mostrar a mensagem “pessoa física”, se informado ‘J’ ou ‘j’
mostrar a mensagem “pessoa jurídica” ou "tipo de pessoa inválido" para qualquer outro caractere.
char Pessoa; //declarar uma variável do tipo char
scanf(“%c”,&Pessoa); //para ler um char
if (Pessoa == ‘f’ || Pessoa == ‘F’) //para comparar se o conteúdo armazenado na variável é um determinado caractere.
*/
int main (void)
{

    char Pessoa;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Iforme se pessoa fisica (F/f) ou juridica (J/j): ");
        scanf("%c",&Pessoa);

        system("cls");

        if(Pessoa == 'J' || Pessoa == 'j')
        {
            printf("\nPessoa Juridica!");
        }
        if(Pessoa == 'F' || Pessoa == 'f')
        {
            printf("\nPessoa Física!");
        }
        else
        {
            printf("Caracter invalido!");
        }

        printf("_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
