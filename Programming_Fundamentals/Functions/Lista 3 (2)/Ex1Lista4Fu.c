#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma função que recebe 3 valores reais a, b e c (parâmetros de entrada) e devolve um valor
que representa o tipo de equação. Como existem vários casos particulares, o valor devolvido pela
função fornece a informação sobre isso. Assim os valores possíveis são:
retorna 1 quando há duas raízes diferentes;
retorna 0 quando há duas raízes iguais;
retorna -1 quando não há raízes reais;
retorna -2 quando a = 0 e b != 0, é equação do primeiro grau;
retorna -3 quando a = 0 e b = 0, ou seja não é equação;
	Tratar o retorna na função chamadora que é a que recebe esse retorno, informando o tipo de
	equação.
*/
int main (void)
{
    int a,b,c,res;
    char Continuar,Opcao;
    do
    {
        system("cls");
        printf("\n___________________________________[BASKARA]___________________________________\n");
        printf("Informe o valor de a: ");
        scanf("%d",&a);
        printf("Informe o valor de b: ");
        scanf("%d",&b);
        printf("Informe o valor de c: ");
        scanf("%d",&c);
        printf("_________________________________________________________________________________\n");
        system("cls");


        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
