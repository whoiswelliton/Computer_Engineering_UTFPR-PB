#include <stdio.h>
#include <stdlib.h>

/*
No intervalo entre 0 e 100, utilizando uma estrutura for para mostrar cada um dos
itens em listagens separadas:
	a) os valores desse intervalo em ordem decrescente.
	b) os valores pares desse intervalo, sem utilizar if, apenas a variável de
	inicializacão, controle e incremento/decremento do for.
	c) os múltiplos de 10, em ordem crescente e sem utilizar if, apenas a variável
	de inicializacão, controle e incremento/decremento do for.
	d) os múltiplos de 5, em ordem decrescente e sem utilizar if, apenas a variável
	de inicializacão, controle e incremento/decremento do for.
*/
int main (void)
{
    char Continuar;
    int Cont=0;

    do
    {
        system("cls");

        printf("\n->_______________________________[Todos]_____________________________________<-\n\n");

        for(Cont=1;Cont<=100;Cont++)
            {
               printf("%d\t",Cont);
            }
        printf("\n->_______________________________[Pares]______________________________________<-\n\n");

        for(Cont=0;Cont<=100;Cont+=2)
            {
                printf("%d\t",Cont);
            }
        printf("\n->__________________________[Divisiveis Por 10]_______________________________<-\n\n");

        for(Cont=0;Cont<=100;Cont+=10)
            {
                printf("%d\t",Cont);
            }
        printf("\n->___________________________[Multiplos de 5]_________________________________<-\n\n");

        for(Cont=100;Cont>=0;Cont-=5)
            {
                printf("%d\t",Cont);
            }

        printf("\n->__________________________________\1________________________________________<-\n\n");

        printf("\nExecutar Novamente (s/S para sim): ");
        getchar();
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

    system("pause");
}
