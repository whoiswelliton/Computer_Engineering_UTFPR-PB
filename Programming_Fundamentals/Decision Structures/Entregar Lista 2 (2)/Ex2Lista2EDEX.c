#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Ler a idade de uma pessoa e informar a sua classe eleitoral, conforme:
Não-eleitor (abaixo de 16 anos)
Eleitor obrigatório (entre 18 e 65 anos)
Eleitor facultativo (entre 16 e 18 e maior de 65 anos).

*/
int main (void)
{

    int Idade;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe sua idade: ");
        scanf("%d",&Idade);

        system("cls");

        if(Idade < 16 && Idade > 0)
        {
            printf("\nNão-eleitor (abaixo de 16 anos)");
        }
        else if(Idade >=18 && Idade <= 65)
        {
            printf("\nEleitor obrigatório (entre 18 e 65 anos)");
        }
        else
        {
            printf("\nEleitor facultativo (entre 16 e 18 e maior de 65 anos).");
        }

        printf("_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
