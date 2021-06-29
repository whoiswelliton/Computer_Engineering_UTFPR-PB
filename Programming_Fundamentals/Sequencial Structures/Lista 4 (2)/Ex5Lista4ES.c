#include <stdio.h>
#include <stdlib.h>

/*
Obter o resto da divisão de dois valores informados pelo usuário, sem usar o operador de resto
*/
int main (void)
{
    int Num1,Num2,Resto,Divisao;

    char Continuar;
    do
    {
        system("cls");
        printf("\n_____________________________________________________________________________\n");
        printf("Informe o primeiro Numero: ");
        scanf("%d",&Num1);
        printf("Informe o Segundo Numero: ");
        scanf("%d",&Num2);

        Divisao = Num1/Num2;
        Resto = Divisao * Num2;
        Resto = Num1 - Resto;

        printf("O resto da divisao e: %.2f",Resto);

        printf("\n____________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
