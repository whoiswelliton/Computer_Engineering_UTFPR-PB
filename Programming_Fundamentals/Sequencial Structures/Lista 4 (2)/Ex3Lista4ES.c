#include <stdio.h>
#include <stdlib.h>

/*
O código a seguir tem como objetivos:
a) fazer a divisão float entre dois valores inteiros informados pelo usuário;
b) Obter o resto da divisão do primeiro número pelo segundo número;
*/
int main (void)
{
    int Num1,Num2;
    float Divisao;
    int Resto;

    char Continuar;
    do
    {
        system("cls");

        printf("Informe o primeiro valor: ");
        scanf("%d",&Num1);
        printf("Informe o segundo valor: ");
        scanf("%d",&Num2);

        Divisao = (float)(Num1/Num2);
        Resto = Num1 % Num2;

        printf("A divisão de %d por %d e: %.2f\n",Num1,Num2,Divisao);
        printf("O resto da divisão e: %d\n",Resto);

        printf("\n_____________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
