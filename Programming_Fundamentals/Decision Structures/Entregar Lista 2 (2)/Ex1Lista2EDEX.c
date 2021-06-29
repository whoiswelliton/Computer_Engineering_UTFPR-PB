#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Ler dois números. Caso sejam ambos pares e se o primeiro é maior que o segundo, mostrar o resto da divisão do
primeiro pelo segundo. Se informado valor zero para o segundo número, que será o divisor, informar que não é
possível realizar divisão por zero.
*/
int main (void)
{

    int Num1,Num2;
    float R1;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe o primeiro numero: ");
        scanf("%d",&Num1);
        printf("Informe o segundo numero: ");
        scanf("%d",&Num2);

        system("cls");

        if(Num1 % 2 == 0 && Num2 %2 == 0)
        {
            if(Num1 > Num2)
            {
                R1 = Num1 % Num2;
                printf("\nResto da divisao do primeiro pelo segundo: %.2f",R1);
            }
            else
            {

            }
        }
        else if(Num2 == 0)
        {
            printf("\n não e possivel realizar divisão por zero.");
        }
        else
        {
            printf("\n Inforem novamente.");
        }

        printf("\n_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
