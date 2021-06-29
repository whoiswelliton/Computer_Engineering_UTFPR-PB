#include <stdio.h>
#include <stdlib.h>

/*
) Faca um algoritmo que leia o sexo, a idade e o tempo de trabalho de uma pessoa e determine se ela pode se
aposentar. Assuma que homens se aposentam com 45 anos de trabalho ou idade superior a 70 anos,
 e mulheres de aposentam com 40 anos de trabalho ou idade superior a 65 anos.
*/
int main (void)
{
    int Idade,Trab;
    char Continuar,Sexo;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe sua Idade: ");
        scanf("%d",&Idade);
        printf("\n________________________________________________________________________________\n");
        printf("Informe seus anos de Trabalho: ");
        scanf("%d",&Trab);
        printf("\n________________________________________________________________________________\n");
        printf("Informe seu Sexo (M/m ou F/f): ");
        scanf("%c",&Sexo);

        system("cls");

        if(Sexo == 'F' || Sexo == 'f')
        {
            if(Trab == 40 || Idade == 65)
            {
                printf("\nVocê pode aposentar-se!");
            }
            else
            {
                printf("\nVocê nao tem idade ou anos de trabalho para aposentar-se!");
            }
        }
        else
        {
            if(Trab == 45 || Idade == 70)
            {
                printf("\nVocê pode aposentar-se!");
            }
            else
            {
                printf("\nVocê nao tem idade ou anos de trabalho para aposentar-se!");
            }
        }


        printf("_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
