#include <stdio.h>
#include <stdlib.h>


/*
Uma livraria fez uma promoção para pagamento à vista em que o comprador pode escolher entre dois critérios
de desconto:
1) 0,25 por livro + 7,50 fixo
2) 0,5 por livro + 2,5 fixo
Fazer um programa em que o usuário digita a quantidade de livros que deseja comprar e o programa diz qual
a melhor opção de desconto.
*/
int main (void)
{

    int Quant,Opcao;
    float Preco;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("Quantos Livros voce deseja comprar: ");
        scanf("%d",&Quant);
        printf("\n_______________________________________________________________________________\n");
        printf("\nOpcao 1 de compra: 0,25 por livro + 7,50 fixo");
        printf("\nOpcao 2 de compra: 0,50 por livro + 2,5 fixo");
        printf("\n_______________________________________________________________________________\n");
        printf("\nQual A Opcao desejada (1 ou 2): ");
        scanf("%d",&Opcao);

        system("cls");

        if(Opcao == 1)
        {
            Preco = (Quant * 0.25)+7.50;
            printf("_______________________________________________________________________________\n");
            printf("\nA Compra de %d Livros vai Custar: %.2f Reais",Quant,Preco);
        }
        else if(Opcao == 2)
        {
            Preco = (Quant * 0.50)+2.50;
            printf("________________________________________________________________________________\n");
            printf("\nA Compra de %d Livros vai Custar: %.2f Reais",Quant,Preco);
        }
        else
        {
            printf("\n                            Opcao Incorreta!\n");

        }

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
