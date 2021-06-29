#include <stdio.h>
#include <stdlib.h>
/*
Ler dez números inteiros. Validar as entradas para que sejam informados valores positivos.
E em listagens separadas:
a) mostrar os pares;
b) mostrar os divisíveis por 3 e por 5 e contar a quantidade deles e mostrar.
c) mostrar os valores menores que 10 e os maiores que 100.
d) mostrar os valores maiores que 10 e menores que 100.
e) mostrar os ímpares e a quantidade de ímpares. Fazer a proporção de ímpares em relação
a quantidade total de números.
O programa permanecerá em execução até que seja escolhida a opção sair ou alguma equivalente.
Fazer as funções na própria main()

*/
int main (void)
{
    char Continuar;
    int Vetor[10],i;

    do
    {
        int Qtd=0,Qtd1=0;
        system("cls");
        printf("\n______________________________________________________________________________\n");
        for(i=0;i<=10;i++)
        {
            do
            {
                printf("Informe o valor para vetor[%d]: ",i);
                scanf("%d",&Vetor[i]);

            }while(Vetor[i] < 0);
        }

        system("cls");
        printf("PARES:\n");
        for(i=0;i<=10;i++)
        {
            if(Vetor[i] % 2 == 0)
            {
                printf("%d\t",Vetor[i]);
            }

        }
        printf("\nDivisíveis por 3 e por 5 e contar a quantidade deles e mostrar:\n");
        for(i=0;i<=10;i++)
        {
            if(Vetor[i] % 3 == 0 && Vetor[i] % 5 == 0)
            {
                printf("%d\t",Vetor[i]);
                Qtd++;

            }
        }
        printf("\nHa %d valores divisiveis por 3 e 5\n",Qtd);

        printf("\nValores menores que 10 e os maiores que 100:\n");
        for(i=0;i<=10;i++)
        {
            if(Vetor[i] < 10 || Vetor[i] > 100)
            {
                printf("%d\t",Vetor[i]);
            }

        }

        printf("\n\nValores maiores que 10 e menores que 100:\n");
        for(i=0;i<=10;i++)
        {
            if(Vetor[i] > 10 && Vetor[i] < 100)
            {
                printf("%d\t",Vetor[i]);
            }
        }

        printf("Impares e a qtd de ímpares. Fazer a proporção de ímpares em relação a quantidade total de números.\n");
        for(i=0;i<=10;i++)
        {
            if(Vetor[i] % 2 != 0)
            {
                printf("%d\t",Vetor[i]);
                Qtd1++;
            }
        }
        printf("\nHa %d valores impares\n",Qtd1);





        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
