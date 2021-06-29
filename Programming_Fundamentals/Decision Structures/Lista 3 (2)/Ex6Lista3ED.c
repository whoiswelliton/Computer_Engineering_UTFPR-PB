#include <stdio.h>
#include <stdlib.h>


/*
Ler um número inteiro verificar se o mesmo possui até 4 dígitos
	a) Se sim, separar os dígitos desse número e mostrá-los em linhas distintas com a indicação do dígito.
Por exemplo:
Lido o número: 1234
Mostrar:
1º - 1
2º - 2
3º - 3
4º - 4
*/
int main (void)
{
    float Num1,M,C,D,U;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe um numero de ate quatro digitos: ");
        scanf("%f",&Num1);

        M = (int)Num1/1000;
        C = (int)Num1%1000 / 100;
        D = (int)Num1%1000%100 / 10;
        U = (int)Num1%10;

        printf("\nNumero lido: %.0f",Num1);
        printf("\n1%c: %.0f",248,M);
        printf("\n2%c: %.0f",248,C);
        printf("\n3%c: %.0f",248,D);
        printf("\n4%c: %.0f",248,U);

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
