#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"
#include "Fatorial.h"
#include "MDC.h"

int main (void)
{
    char Continuar,Opcao;
    int N,P,Comb,Maior,Menor,Div;

    do
    {
        system("cls");
        printf("________________________________________________________________________________\n");
        printf("                       1 - Combinacoes Fatorial\n");
        printf("                       2 - MDC (Maior Divisor Comum) \n");
        printf("                       3 - MMC (Minimo Multiplo Comum) \n");
        printf("                       4 - Sair\n");
        printf("________________________________________________________________________________\n\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%c",&Opcao);
        printf("\n");

        switch (Opcao)
        {
            case'1':
            {
                do
                {
                    printf("Informe o primeiro valor: ");
                    scanf("%d",&N);
                    printf("\n");
                    printf("Informe o Segundo valor: ");
                    scanf("%d",&P);
                    printf("\n\n");

                }while(N <= 0 && P <= 0);

                if( N - P > 0)
                {
                    Comb = Fatorial(N)/(Fatorial(P) * Fatorial(N - P));

                    printf("                       Combinacoes dos Elementos: %d\n\n\n",Comb);
                    printf("________________________________________________________________________________\n\n");
                }
                else
                {
                    printf("                      Numeros Invalidos! Tente Novamente.\n\n\n");
                }

                break;
            }
            case'2':
            {
                do
                {
                    printf("Informe o primeiro valor: ");
                    scanf("%d",&N);
                    printf("\n");
                    printf("Informe o Segundo valor: ");
                    scanf("%d",&P);
                    printf("\n\n");

                    Div = MDC(N,P);

                    if(Div > 0)
                    {
                            printf("                       O Maior Divisor Comum (MDC): %d\n\n\n",Div);
                            printf("________________________________________________________________________________\n\n");
                    }

                }while(N <= 0 && P <= 0);

                break;
            }
            case'3':
            {
                do
                {
                    printf("Informe o primeiro valor: ");
                    scanf("%d",&N);
                    printf("\n");
                    printf("Informe o Segundo valor: ");
                    scanf("%d",&P);
                    printf("\n");


                    if(Div > 0)
                    {
                            printf("                       O Minimo Multiplo Comum (MMC): %d\n\n\n",Div);
                            printf("________________________________________________________________________________\n\n");
                    }

                }while(N <= 0 && P <= 0);

                break;
            }
            case'4':
            {
                printf("                       Pressione ENTER para Finalizar...\n\n\n\n\n");
                exit(0);
            }

            default:
            printf("                           Opcao Invalida!\n\n");
        }



        Pause();

        printf("\nExecutar novamente (S/s para sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

