#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Fazer um algoritmo que leia um valor float que representa o salário de uma pessoa.
Apresente separadamente os reais (parte inteira) e os centavos (parte decimal).
 Observação: apresentar os centavos como inteiro de dois dígitos (98 em vez de 0.98)
Exemplo:
Salário informado: 1345.98
Reais: 1345
Centavos: 98

*/
int main (void)
{

    float Salario,reais,cent;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe seu salario: ");
        scanf("%f",&Salario);
        printf("__________________________________________________________________________________\n");

        reais = (int)Salario;
        cent = Salario - (int)Salario;

        system("cls");

        printf("\nSalario informado: %.0f ",Salario);
        printf("\nReais: %.0f",reais);
        printf("\nCentavos: %.2f",cent);

        printf("\n\n_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
