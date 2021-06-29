#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"

/*
 Ler um número inteiro e imprimir o seu sucessor, sem alterar o conteúdo da variável, e antecessor,
  alterando o conteúdo da variável.
*/

int main (void)
{
    char Continuar;
    int Num1,Num2,Num3;

    do
    {
        system("cls");
        printf("________________________________________________________________________________\n");
        printf("Informe o um numero: ");
        scanf("%d",&Num1);
        printf("\n________________________________________________________________________________\n");
        system("cls");

        printf("\nAntecessor = %d",Num1+1);
        printf("\nSucessor = %d",Num1-1);

        Num2 = Num1+1;
        Num3 = Num1-1;

        printf("\n\nAntecessor usando outra variavel = %d",Num3);
        printf("\nSucessor usando outra variavel = %d",Num2);


        printf("\n\nPara Executar Novamente (S/s para sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}

