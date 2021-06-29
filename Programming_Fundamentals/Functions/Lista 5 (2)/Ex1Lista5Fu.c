#include <stdio.h>
#include <stdlib.h>
#include "Funcao1.h"

/*
Fazer uma função para verificar se um número é quadrado perfeito. Um número é quadrado perfeito se pode ser obtido com
a soma dos n primeiros números
ímpares iniciando em 1. Por exemplo, 9, é quadrado perfeito porque a raiz quadrada é 3 ou porque 1 + 3 + 5 = 9 (soma
 dos n primeiros números ímpares inciando em 1). Essa função recebe como parâmetro um valor inteiro e retorna 's' se
  o núnero é um quadrado perfeito e 'n' caso não.
Usar essa função para (usar obrigatoriamente a mesma função):
a) Ler um número interiro informado pelo usuário é verificar se o mesmo é um quadrado perfeito.
b) Ler um número float informado pelo usuário e verificar se a parte inteira desse número é um quadrado perfeito.
c) Mostrar os números que são quadrados perfeitos de um intervalo, com os valores (limite superior e inferior)
 informados pelo usuário.
*/
int main (void)
{
    char Continuar,Opcao;
    int Valor1,Valor2,Cont;
    float ValorF;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("a)Ler um número interiro informado pelo usuário é verificar se o mesmo é um quadrado perfeito\n");
        printf("b)Ler um número float informado pelo usuário e verificar se a parte inteira desse número é um quadrado perfeito.\n");
        printf("c)Mostrar os números que são quadrados perfeitos de um intervalo, com os valores (limite superior e inferior) informados pelo usuário.\n");
        printf("_________________________________________________________________________________\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%c",&Opcao);
        switch(Opcao)
        {
            case 'a':
            {
                printf("Informe um valor inteiro: ");
                scanf("%d",&Valor1);
                Opcao = Quadradoperfeito(Valor1);
                if(Opcao == 's')
                {
                    printf("%d e quadrado perfeito",Valor1);
                }
                else
                {
                    printf("%d nao e quadrado perfeito",Valor1);
                }
                break;
            }
            case 'b':
            {
                printf("Informe um valor float: ");
                scanf("%f",&ValorF);
                Valor1 = (int)ValorF;

                Opcao = Quadradoperfeito(Valor1);
                if(Opcao == 's')
                {
                    printf("%d e quadrado perfeito",Valor1);
                }
                else
                {
                    printf("%d nao e quadrado perfeito",Valor1);
                }

                break;
            }
            case 'c':
            {
                printf("Informe o limite inferior do intervalo: ");
                scanf("%d",&Valor1);
                printf("Informe o limite superior do intervalo: ");
                scanf("%d",&Valor2);
                for(Cont+Valor1;Cont<=Valor2;Cont++)
                {
                    if(Quadradoperfeito(Cont) == 's')
                    {
                        printf("%d\t",Cont);
                    }
                }

            }
        }
        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
