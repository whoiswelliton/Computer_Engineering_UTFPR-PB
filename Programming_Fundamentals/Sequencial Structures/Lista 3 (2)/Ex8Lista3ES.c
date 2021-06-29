#include <stdio.h>
#include <stdlib.h>

/*
Leia um número do tipo float. Obtenha e mostre o resto da divisão da parte inteira desse número por cinco.
 A parte decimal multiplique-a por 10 e em seguida
 mostre o resto da divisão desse número por 3.
Exemplo: Informado: 11.756
	Inteiro: 11
	Resto da dividido por 5: 1
	Parte decimal: 0.756
Parte decimal multiplicada por 10: 7
	Resto da divisão por 3 da parte decimal multiplicada por 10: 1
*/
int main (void)
{
    char Continuar;
    float Num,div,dec,mult,Inteiro;

    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe um Numero: ");
        scanf("%f",&Num);

        system("cls");

        Inteiro = (int)Num;
        div = (int)Num % 5;
        dec = Num - (int)Num;
        mult = dec*10;

        printf("\nInteiro: %.0f",Inteiro);
        printf("\nResto da dividido por 5: %.0f",div);
        printf("\nParte decimal: %.3f",dec);
        printf("\nParte decimal multiplicada por 10: %.0f",mult);

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                          Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

