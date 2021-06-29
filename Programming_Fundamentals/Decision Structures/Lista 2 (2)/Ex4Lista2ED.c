#include <stdio.h>
#include <stdlib.h>

/*
Ler a altura e o sexo de uma pessoa (F ou f para feminino e M ou m para masculino, se outro caractere,
 informar que é inválido e finalizar o programa)
e construir um algoritmo que calcule seu peso ideal, utilizando as seguintes fórmulas:
a) para homens: (72,7 * h) - 58;
b) para mulheres: (62,1 * h) - 44,7.
Observação, para ler caractere e comparar variável do tipo caractere:
char Pessoa;
scanf(“%c”,&Pessoa);
if (Pessoa == ‘f’ || Pessoa == ‘F’)
*/
int main (void)
{
    float Altura,Peso;
    char Continuar,Sexo;

    do
    {
        system("cls");

        printf("\n_______________________________________________________________________________\n");
        printf("Informe o Sexo (M/m ou F/f): ");
        scanf("%c",&Sexo);
        getchar();
        printf("\n_______________________________________________________________________________\n");
        printf("Informe sua Altura: ");
        scanf("%f",&Altura);

        system("cls");

        if(Sexo == 'M' || Sexo == 'm')
        {
            Peso = (72.7 * Altura) - 58;
            printf("Seu peso ideal: %.2f",Peso);
        }
        else if(Sexo == 'F' || Sexo == 'f')
        {
            Peso = (62.1 * Altura) - 44.7;
            printf("Seu peso ideal: %.2f",Peso);
        }
        else
        {
            printf("Informe um Caractere valido!");
        }

        printf("\n_____________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
