#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Ler um valor que representa o preço de um produto e imprimir esse valor com reajuste de X%.
Sendo que o percentual do reajuste é informado pelo usuário.
*/
int main (void)
{
    char Continuar;
    float P,T,R;
    do
    {
        system("cls");
        printf("\n_____________________________________________________________________________\n");
        printf("Informe o preco do Produto: ");
        scanf("%f",&P);
        printf("_______________________________________________________________________________\n");
        printf("Informe o valor do reajuste: ");
        scanf("%f",&R);


        T = P+P*(float)(R/100);

        printf("\nO preco final do produto com reajustes %c: %.2f",130,T);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
