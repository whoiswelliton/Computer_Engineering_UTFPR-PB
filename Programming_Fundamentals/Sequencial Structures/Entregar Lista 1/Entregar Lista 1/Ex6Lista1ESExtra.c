#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
) Escreva um algoritmo que leia dois valores que são o raio e altura de um cilindro e calcule o seu volume,
cuja fórmula é: Volume = 3.1415 * Raio2 * Altura.
*/
int main (void)
{
    char Continuar;
    float Raio,Alt,Volume;
    do
    {
        system("cls");
        printf("\n_____________________________________________________________________________\n");
        printf("Informe o Raio do Cilindro: ");
        scanf("%f",&Raio);
        printf("Informe a Altura do Cilindro: ");
        scanf("%f",&Alt);

        Volume = 3.1415 * Raio * Alt;

        printf("\nO Volume do cilindro %c: %.2f",130,Volume);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
