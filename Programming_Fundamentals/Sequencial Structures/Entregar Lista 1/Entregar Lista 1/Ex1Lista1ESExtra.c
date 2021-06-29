#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Uma pessoa foi ao supermercado e comprou:
    M quilos de maçã a um custo unitário de x;
    L litros de leite a um custo unitário de y;
    B pacotes de biscoito a um custo unitário de z;
    Fazer um programa para ler a quantidade de cada um dos produtos comprados e o seu valor unitário.
     Calcular o valor total de cada tipo de produto e o valor total da compra. Mostrar o nome do produto,
      a quantidade comprada e o preço de cada produto, bem como o valor total da compra.

*/
int main (void)
{
    char Continuar;
    int M,L,B;
    float X,Y,Z,T1,T2,T3,T;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe quantos quilos de maca foram comprados: ");
        scanf("%d",&M);
        printf("Informe o custo de 1 quilo da maca: ");
        scanf("%f",&X);

        printf("\n________________________________________________________________________________\n");
        printf("Informe quantos litros de leite foram comprados: ");
        scanf("%d",&L);
        printf("Informe o custo de 1 litro de leite: ");
        scanf("%f",&Y);

        printf("\n______________________________________________________________________________\n");
        printf("Informe quantos pacotes de biscoito foram comprados: ");
        scanf("%d",&B);
        printf("Informe o custo de 1 pacote de biscoito: ");
        scanf("%f",&Z);

        system("cls");

        T1 = M * X;
        T2 = L * Y;
        T3 = B * Z;
        T = T1 + T2 + T3;

        printf("\n_______________________________________________________________________________\n");
        printf("O preco final de %d quilos de maca a %.2f reais o quilo %c: %.2f",M,X,130,T1);
        printf("\nO preco final de %d litos de leite a %.2f reais o litro %c: %.2f",L,Y,130,T2);
        printf("\nO preco final de %d pacotes de biscoito a %.2f reais o pacote %c: %.2f",B,Z,130,T3);
        printf("\n_______________________________________________________________________________\n");
        printf("\nO preco total da compra: %.2f",T);

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
