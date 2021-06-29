#include <stdio.h>
#include <stdlib.h>
/*
3) Ler um número N qualquer maior ou igual a 1 e menor ou igual a 50 e apresentar o valor obtido da multiplicação
sucessiva de N por 2, enquanto o produto for menor que 250 (N*2; N*2*2; N*2*2*2; etc.). O valor N deverá ser
verificado quanto a sua validade. Caso o usuário informe um valor fora da faixa, o programa deverá informar
que o valor digitado não é válido e repetir a leitura.
*/
int main (void)
{
    int Num;
    char Continuar;

    do
    {
        system("cls");

        do
        {
            printf("Informe um valor: ");
            scanf("%d",&Num);
            if(Num <1 || Num >50);
            {
                printf(" O Valor deve estar entre 1 e 50\n");
            }
        }while(Num <1 || Num >50);

        do
        {
            if(Num*2 < 250)
            {
            Num *= 2;
            printf("%d\n",Num);
            }
            else
            {
                break;
            }

        }while(Num <= 250);

        printf("\nExecutar novamente (S/s para sim): ");
        getchar();
        scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');


    system("pause");
}
