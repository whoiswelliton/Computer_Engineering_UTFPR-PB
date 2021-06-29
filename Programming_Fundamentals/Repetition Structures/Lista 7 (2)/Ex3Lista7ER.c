#include <stdio.h>
#include <stdlib.h>

/*
 Ler um número N qualquer maior ou igual a 1 e menor ou igual a 50 e apresentar o valor obtido da multiplicação
 sucessiva de N por 2, enquanto o produto for menor que 250 (N*2; N*2*2; N*2*2*2; etc.). O valor N deverá ser
 verificado quanto a sua validade. Caso o usuário informe um valor fora da faixa, o programa deverá informar
 que o valor digitado não é válido e repetir a leitura.
*/
int main (void)
{
    int Num,Cont,Soma=0,Produto=0;
    char Continuar;
    do
    {
        do
        {
            system("cls");
            printf("\n_______________________________________________________________________________\n");
            printf("Informe um numero: ");
            scanf("%d",&Num);
            if(Num < 1 && Num > 50)
            {
                printf("informe um numero entre 1 e 50.");
            }
        }while(Num < 1 && Num > 50);

        do
        {
            Soma = Num * 2;
            Produto = Soma * 2;
            printf("%d x 2 = %d",Soma,Produto);

        }while(Produto < 250);


        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
