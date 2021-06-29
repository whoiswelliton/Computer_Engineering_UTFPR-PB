#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"
/*
 Faça uma função que recebe, por parâmetro, um valor inteiro e positivo e retorna a quantidade de divisores de um número.
a) Usar essa função para mostrar a quantidade de divisores de valores informados pelo usuário. Repetir a leitura enquanto informados valores positivos.
b) Usar essa função para mostrar a quantidade de divisores de um intervalo informado pelo usuário. O intervalo deve ser apresentado em ordem crescente,
independentemente da ordem que o usuário informou os valores.
c) Usar essa função para verificar e apresentar a maior quantidade de divisores, e o respecitivo valor que a contém, de números informados pelo usuário.
 Repetir a leitura enquanto informados valores positivos.
*/
int main (void)
{
    int Num,Retorno,Lim1,Lim2,Aux,Cont;
    char Continuar,Opcao;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Escolha uma Opcao:\n");
        printf("\n1 - Programa 1");
        printf("\n2 - Programa 2");
        printf("\n3 - Programa 3");
        printf("\n5 - Sair");
        printf("\n________________________________________________________________________________\n");
        printf("\nOpcao: ");
        fflush(stdin);
        scanf("%c",&Opcao);

        system("cls");

        switch(Opcao)
        {
            case '1':
            {
                do
                {
                    printf("\nInforme um valor: ");
                    scanf("%d",&Num);

                    if(Num < 0)
                    {
                        printf("\n\nValor Negativo Informado, Informe Novamente!");
                    }
                }while(Num <0);


                Retorno = Qtdivisores1 (Num);

                printf("\n________________________________________________________________________________\n");
                printf("\nO Numero informado tem %d Divisores.",Retorno);

                break;
            }
            case '2':
            {
                do
                {
                    printf("\nInforme o Primeiro Limite: ");
                    scanf("%d",&Lim1);
                    printf("\nInforme o Segundo Limite: ");
                    scanf("%d",&Lim2);

                    if(Lim1 < 0 || Lim2 < 0)
                    {
                        printf("\n\nAlgum dos Limites informados %c Negativo.Informe Novamente!",130);
                    }
                }while(Lim1 < 0 || Lim2 < 0);


                if(Lim1 < Lim2)
                {
                    Aux = Lim1;
                    Lim1 = Lim2;
                    Lim2 = Aux;
                }

                for(Cont=Lim2;Cont<=Lim1;Cont++)
                {
                    Retorno = Qtdivisores2(Cont);
                    printf("%d\t",Retorno);
                }

                break;
            }
            case '3':
            {

                break;
            }
            case '4':
            {
                printf("\n\n                Pressione ENTER para finalizar...");
                exit(0);
            }
            default:
            {
                printf("Opcao Invalida!");
            }
        }
        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
