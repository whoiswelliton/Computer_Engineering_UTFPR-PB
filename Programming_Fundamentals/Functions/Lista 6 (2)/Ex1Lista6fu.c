#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

/*
 Fazer uma função para mostrar os divisores de um número. Fazer outra função para retornar a quantidade
 de divisores de um número. Fazer outra função para calcular a soma dos divisores de um número.
 Utilizas essas funções para:
a) Mostrar a quantidade de divisores de um número informado pelo usuário.
b) Mostrar os divisores de um número informado pelo usuário.
c) Mostrar os divisores, a quantidade de divisores e a soma desses divisores de um intervalo de números.
 O usuário informar os limites desse intervalo.
*/
int main (void)
{

    int Qtdiv=0,Num,Soma,Lim1,Lim2,retorno,Cont;
    char Continuar,Opcao;
    do
    {
        system("cls");
        printf("1 - quantidade de divisores de um número\n");
        printf("2 - divisores de um número\n");
        printf("3 - divisores,quantidade de divisores e a soma dos divisores de um intervalo\n");
        printf("Opcao: ");
        scanf("%c",&Opcao);
        switch(Opcao)
        {
            case '1':
            {
                printf("Informe um numero: ");
                scanf("%d",&Num);

                retorno = Qtdivisores1(Num);

                printf("%d possui %d divisores",Num,retorno);

                break;
            }
            case '2':
            {
                printf("Informe um numero: ");
                scanf("%d",&Num);

                retorno = mostrardivisores (Num);

                break;
            }
            case '3':
            {
                printf("Informe o primeiro limite do intervalo: ");
                scanf("%d",&Lim1);
                printf("Informe o segundo limite do intervalo: ");
                scanf("%d",&Lim2);
                for(Cont=Lim1;Cont<=Lim2;Cont++)
                {
                    printf("%d - ",Cont);
                    mostrardivisores(Cont);
                    retorno = Qtdivisores1(Cont);
                    printf(" Qtde: %d",retorno);
                    printf(" Soma: %d\n",somardividores(Cont));
                }

                break;
            }
            default:
            {
                printf("Opção Invalida\n");
            }
        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

