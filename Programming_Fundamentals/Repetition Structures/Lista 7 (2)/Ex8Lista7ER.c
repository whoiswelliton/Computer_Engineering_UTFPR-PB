#include <stdio.h>
#include <stdlib.h>

/*
No intervalo entre 0 e 100, utilizando uma estrutura for para mostrar cada um dos itens em listagens separadas:
	a) os valores desse intervalo em ordem decrescente.
	b) os valores pares desse intervalo, sem utilizar if, apenas a variável de inicializacão, controle e
	incremento/decremento do for.
	c) os múltiplos de 10, em ordem crescente e sem utilizar if, apenas a variável de inicializacão,
	controle e incremento/decremento do for.
	d) os múltiplos de 5, em ordem decrescente e sem utilizar if, apenas a variável de inicializacão,
	controle e incremento/decremento do for.
*/
int main (void)
{
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf(" ");

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
