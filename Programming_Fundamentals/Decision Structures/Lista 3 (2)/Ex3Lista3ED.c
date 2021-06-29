#include <stdio.h>
#include <stdlib.h>


/*
Ler dois números inteiros informar:
a) Se pelo menos deles é divisível por 5.
b) Se somente um deles é divisível por 5.
Exemplo: 10 e 15 pelos menos um é divisível por 5.
Exemplo: 3 e 5 pelos menos um é divisível por 5 e somente um deles é divisível por 5.
c) Se ambos são pares.
d) Se pelo menos um deles é ímpar.
Esses quatro itens podem ser realizados utilizando uma única estrutura if else if encadeada? Por quê?

*/
int main (void)
{
    int Num1,Num2,div;
    char Continuar;

    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("Informe o primeiro numero inteiro: ");
        scanf("%d",&Num1);
        printf("Informe o segundo numero inteiro: ");
        scanf("%d",&Num2);

        system("cls");

        if(Num1 % 5 == 0 || Num2 % 5 == 0)
        {
            printf("\n%d e %d pelo menos um e divisivel por 5.",Num1,Num2);
        }
        else if(Num1 % 5 == 0 && Num2 % 5 != 0 || Num1 % 5 != 0 && Num2 % 5 == 0)
        {
            printf("\nSomente um deles é divisível por 5.");
        }
        else
        {
            printf("Nenhum e divisivel por 5");
        }

        if(Num1 % 2 == 0 && Num2 % 2 == 0)
        {
            printf("\nAmbos sao pares");
        }
        else if(Num1 % 2 == 0 && Num2 % 2 != 0 || Num1 % 2 != 0 && Num2 % 2 == 0)
        {
            printf("\nPelo menos um deles e impar");
        }


        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
