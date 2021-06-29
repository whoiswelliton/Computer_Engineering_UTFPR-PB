
#include <stdio.h>
#include <stdlib.h>

/*
Ler dois valores numéricos e apresentar a diferença entre eles. A diferença sempre é positiva, portanto,
 o menor é subtraído do maior não importando a ordem em que os números são informados.
*/
int main (void)
{
    float Num1,Num2,Num3,Num4;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Inform o Primeiro Numero:");
        scanf("%f",&Num1);
        printf("Inform o Segundo Numero:");
        scanf("%f",&Num2);

        Num3=Num1-Num2;

        if(Num3 < 0)
        {
            Num4 =Num3*-1;
            printf("A diferença entre eles %c de: %.2f",130,Num4);
        }
        else
        {
            printf("\nA diferença entre eles %c de: %.2f",130,Num3);
        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
