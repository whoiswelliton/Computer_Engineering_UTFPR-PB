#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Escreva um algoritmo para ler o salário mensal de um funcionário e o percentual de reajuste.
 Calcular e mostrar o valor do novo salário.
*/
int main (void)
{
    char Continuar;
    float S,T,R;
    do
    {
        system("cls");
        printf("\n_____________________________________________________________________________\n");
        printf("Informe o Salario: ");
        scanf("%f",&S);
        printf("_______________________________________________________________________________\n");
        printf("Informe o percentual de reajuste: ");
        scanf("%f",&R);


        T = S+S*(float)(R/100);

        printf("\nO Salario Final com reajustes %c: %.2f",130,T);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}

