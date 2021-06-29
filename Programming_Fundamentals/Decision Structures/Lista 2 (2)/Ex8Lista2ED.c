#include <stdio.h>
#include <stdlib.h>

/*
Ler um número e utilizando uma estrutura if else if  else if... (obrigatoriamente encadeada)
informar se ele é:
a) divisível somente por 5, por 3 ou por 2;
Exemplo: 25 divisível somente por 5
b) não é divisível por nenhum destes;
Exemplo: 7 não é divisível por 5, 3 ou 2;
c) se é divisível por todos eles;
Exemplo: 30 é divisível por 2, 3 e 5.
d) se ele é divisível somente por 5 e por 3; por 5 e por 2; ou por 3 e por 2;
Exemplo: 15 é divisível somente por 3 e por 5.
Exemplo: 10 é divisível somente por 5 e por 2.
Exemplo: 6 é divisível somente por 3 e por 2.
Nesse exercício faz diferença a ordem em que as comparações são realizadas? Por quê?
*/
int main (void)
{
    int Num;
    char Continuar;
    do
    {
        system("cls");
        printf("\n______________________________________________________________________________\n");
        printf("Informe um Numero: ");
        scanf("%d",&Num);

        system("cls");

        if(Num % 5 == 0 && Num % 3 == 0 && Num % 2 == 0)
        {
            printf("E Divisivel por 5, 3 e 2.");
        }

        else if(Num % 5 == 0 && Num % 3 != 0 && Num % 2 != 0)
        {
            printf("E Divisivel somente por 5.");
        }

        else if(Num % 5 != 0 && Num % 3 == 0 && Num % 2 != 0)
        {
            printf("E Divisivel somente por 3.");
        }

        else if(Num % 5 != 0 && Num % 3 != 0 && Num % 2 == 0)
        {
            printf("E Divisivel somente por 2.");
        }

        else if(Num % 5 == 0 && Num % 3 == 0 && Num % 2 != 0)
        {
            printf("E Divisivel por 5 e 3.");
        }

        else if(Num % 5 == 0 && Num % 3 != 0 && Num % 2 == 0)
        {
            printf("E Divisivel por 5 e 2.");
        }

        else if(Num % 5 != 0 && Num % 3 == 0 && Num % 2 == 0)
        {
            printf("E Divisivel por 2 e 3.");
        }

        else
        {
            printf("Nenhum e Divisivel");
        }






        printf("\n\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
