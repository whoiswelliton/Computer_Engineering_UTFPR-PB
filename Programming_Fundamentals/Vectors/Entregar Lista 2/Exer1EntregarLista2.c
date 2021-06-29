#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Ler uma string. Percorrer essa string armazenando em outra os caracteres em índice par e em outra os
caracteres em índice ímpar. É indispensável finalizar as strings geradas, ou seja, armazenar ‘\0’,
como último caractere. Mostrar as três strings.
Dica: Após percorrer a string armazenando os caracteres nos respectivos vetores (cada vetor terá um
 índice próprio), armazenar no respectivo índice o caractere ‘\0’. Por exemplo:
VetIndicePar[IndicePar]=’\0’;
VetIndiceImpar[IndiceImpar]=’\0’;
Quando a estrutura de repetição que percorreu a string original foi finalizada as variáveis IndicePar
 e ÍndiceImpar contém o último índice mais 1, geralmente em uma forma de implementação normalmente utilizada.

*/
int main (void)
{
    char Continuar;
    do
    {
        system("cls");


        printf("_____________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
