#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/*
Validar um endereço de email, utilizando as seguintes regras:
a) ter um e somente um símbolo de @;
b) @ não pode ser o primeiro caractere;
c) não pode finalizar com @, tem que ter pelo menos um caractere após;
d) não pode haver espaços em branco entre os caracteres do endereço.
Definir uma função para essa validação. A função retorna 's' se o e-mail é válido, de acordo com as regras,
e 'n' se não for válido.

*/

int main (void)
{
    char Continuar,email[30];
    int i,j,Cont,Cont2;

    do
    {
        system("cls");

        i=j=0;
        Cont=Cont2=0;

        printf("Informe seu E-Mail: ");
        fflush(stdin);
        gets(email);


        for(i=0;email[i] != '\0';i++)
        {
            j++;
        }



        for(i=0;i<j;i++)
        {
            if(email[i] == '@')
            {
                Cont++;
            }
            if(email[i] == ' ')
            {
                Cont2++;
            }

        }


        if(Cont == 1 && email[0] != '@'&& email[j] != '@' && Cont2 == 0)
        {
            printf("\n\nEmail Valido\n\n");

        }
        else
        {
            printf("\n\nEmail Invalido\n\n");
        }


        printf("\n\nPara executar novamente: ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');

}
