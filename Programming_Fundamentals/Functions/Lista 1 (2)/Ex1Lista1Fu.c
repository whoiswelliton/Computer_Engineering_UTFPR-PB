#include <stdio.h>
#include <stdlib.h>

/*
Fazer uma calculadora com as operações de soma, subtração, multiplicação, divisão e resto.
Cada operação é uma função e deve ser acessada a partir de um menu. As funções são implementadas
 na próprio programa:
a) Soma sem parâmetros e sem retorno
b) Subtração com parâmetros e sem retorno
c) Multiplicação sem parâmetros e com retorno
d) Divisão com parâmetros e com retorno.
e) Resto com parâmetros e com retorno.
*/

void Soma(void);
void Subtracao(int Num1,int Num2);
int Multiplicacao (void);
float Dividir (int Num1, int Num2);
float Resto (int Num1, int Num2);

int main (void)
{
    char Continuar,Opcao;
    int Num1,Num2;
    float Retorno;

    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("Escolha um Opcao:\n");
        printf("\n                                 1 - Soma\n");
        printf("\n                                 2 - Subtracao\n");
        printf("\n                                 3 - Multiplicacao\n");
        printf("\n                                 4 - Divisao\n");
        printf("\n                                 5 - Resto\n");
        printf("\n                                 6 - Sair\n");
        printf("\n_______________________________________________________________________________\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%c",&Opcao);

        system("cls");

        switch(Opcao)
        {
            case '1':
            {
                Soma();
                break;
            }
            case '2':
            {
                printf("Informe o primeiro valor: ");
                scanf("%d",&Num1);
                printf("Informe o segundo valor: ");
                scanf("%d",&Num2);
                Subtracao(Num1,Num2);

                break;
            }
            case '3':
            {
                Retorno = Multiplicacao();
                printf("Multiplicacao: %.0f\n",Retorno);
                break;
            }
            case '4':
            {
                printf("Informe o primeiro valor: ");
                scanf("%d",&Num1);
                printf("Informe o segundo valor: ");
                scanf("%d",&Num2);

                Retorno = Dividir(Num1,Num2);

                printf("Divisao: %.0f\n",Retorno);
                break;
            }
            case '5':
            {
                printf("Informe o primeiro valor: ");
                scanf("%d",&Num1);
                printf("Informe o segundo valor: ");
                scanf("%d",&Num2);

                Retorno = Resto(Num1,Num2);

                printf("Resto = %.0f\n",Retorno);
                break;
            }
            case '6':
            {
                exit(0);
            }
            default :
            {
                printf("\nOpcao Invalida!");
            }
        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

void Soma (void)
{
    int Num1,Num2,Soma;

    printf("\nInforme o primeiro numero: ");
    scanf("%d",&Num1);
    printf("\nInforme o segundo numero: ");
    scanf("%d",&Num2);

    Soma = Num1 + Num2;

    printf("\nA Soma e igual a: %d",Soma);

}

void Subtracao(int Num1, int Num2)
{
    int Sub;

    Sub = Num1 - Num2;
    printf("\nResultado da Subtracao: %d",Sub);
}

int Multiplicacao (void)
{
    int Num1,Num2,Mult;

    printf("\nInforme o primeiro Numero:");
    scanf("%d",&Num1);
    printf("\nInforme o segundo Numero:");
    scanf("%d",&Num2);

    Mult = Num1 * Num2;

    return(Mult);
}

float Dividir (int Num1, int Num2)
{
    float Div;

    Div = (float)Num1/Num2;

    return(Div);
}

float Resto (int Num1, int Num2)
{
    float Resul;

    Resul = Num1 % Num2;

    return(Resul);
}
