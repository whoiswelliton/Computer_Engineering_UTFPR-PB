#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Ler o tipo de carro (A, B e C) e o percurso realizado em km. Calcular o consumo estimado, conforme o tipo,
 sendo A=8, B=9 e C=12 km/litro.
*/
int main (void)
{
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf(" ");

        printf("_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
