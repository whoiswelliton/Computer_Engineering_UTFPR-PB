#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"
#include "Vetores1.h"

/*
Gerar aleatoriamente 8 elementos para um vetor A. Construir um vetor B de mesma dimensão com
os elementos de A multiplicados por 2.

*/
int main (void)
{
    char Continuar,Opcao;
    int i,N,Vet,Tam,Soma=0,QtVet=0,QtVet2=0,Soma2=0;
    float Media;

    do
    {
        system("cls");
        Soma2=0;
        Soma=0;
        QtVet=0;
        QtVet2=0;
        printf("________________________________________________________________________________\n");
        printf("1 - Gerar aleatoriamente 8 elementos para um vetor A,\n");
        printf("    Construir um vetor B de mesma dimensao com os elementos de\n");
        printf("    A multiplicados por 2.");
        printf("\n\n");
        printf("2 - Gerar aleatoriamente 7 elementos para um vetor A,Construir\n");
        printf("    um vetor B de mesmo tipo, sendo que cada elemento de B devera\n");
        printf("    ser o elemento de A correspondente multiplicado por sua posicao.");
        printf("\n\n");
        printf("3 - Gerar aleatoriamente 10 elementos para um vetor A e construir um vetor B\n");
        printf("    de mesma dimensao com os mesmos elementos de A, mas em ordem invertida.");
        printf("\n\n");
        printf("4 - Gerar aleatoriamente 10 elementos para um vetor.Calcular e mostrar:\n");
        printf("    a) A soma de elementos armazenados nesse vetor que sao inferiores a 100.\n");
        printf("    b) A quantidade de elementos armazenados nesse vetor que sao iguais a 100.\n");
        printf("    c) A media dos elementos armazenados nesse vetor que sao superiores a 100.\n");
        printf("\n");
        printf("5 - Gerar aleatoriamente dois vetores A e B com x elementos.");
        printf("\n\n");
        printf("6 - Sair");
        printf("\n\n");
        printf("________________________________________________________________________________\n");
        printf("                                OPCAO: ");
        fflush(stdin);
        scanf("%c",&Opcao);
        printf("\n");

        switch(Opcao)
        {
            case '1':
            {
                Tam=8;
                int VetorA[8];
                int VetorB[8];

                GerarVetor(VetorA,Tam,20);

                MostrarVetor(VetorA,Tam);
                break;
            }
            case '2':
            {
                Tam=7;
                int VetorA[7];
                int VetorB[7];

                GerarVetor(VetorA,Tam,20);
                MostrarVetor(VetorA,Tam);

                for(i=0;i<7;i++)
                {
                    VetorB[i] = VetorA[i] * i;

                }

                printf("\n\n Vetor B: \n");
                for(i=0;i<7;i++)
                {
                    printf("%d\t",VetorB[i]);

                }
                printf("\n________________________________________________________________________________");
                break;
            }
            case '3':
            {
                Tam=10;
                int VetorA[10];
                int VetorB[10];

                GerarVetor(VetorA,Tam,20);
                MostrarVetor(VetorA,Tam);

                for(i=0;i<10;i++)
                {
                    VetorB[i]=VetorA[10-i-1];
                }

                printf("\n\n Vetor B: \n");
                for(i=0;i<10;i++)
                {
                    printf("%d\t",VetorB[i]);

                }
                printf("\n________________________________________________________________________________");
                break;
            }
            case '4':
            {
                Tam=10;
                int VetorA[10];
                fflush(stdin);

                GerarVetor(VetorA,Tam,200);
                MostrarVetor(VetorA,Tam);

                for(i=0;i<10;i++)
                {
                    Soma=Soma +VetorA[i];

                    if(VetorA[i] == 100)
                    {
                        QtVet++;
                    }
                    if(VetorA[i] > 100)
                    {
                        Soma2=Soma2 +VetorA[i];
                        QtVet2++;
                    }

                }
                if(QtVet2 > 0)
                {
                    Media = (float)Soma2/QtVet2;
                }

                printf("\n a)\n");
                printf("   Soma dos Vetores = %d\n",Soma);
                printf("\n b)\n");
                printf("   Quantidade de Vetores iguais a 100 = %d\n",QtVet);
                printf("\n c)\n");
                printf("   Media dos Vetores maiores que 100 = %.2f\n",Media);
                printf("\n________________________________________________________________________________");

                break;
            }
            case '5':
            {
                do
                {
                    printf("Informe A Quantidade de elementos dos Vetores: ");
                    scanf("%d",&N);
                    if(N <= 0)
                    {
                        printf("Informe um valor Positivo seu LOSER!");
                    }

                }while(N < 0);

                Tam = N;
                int VetorA[N];
                int VetorB[N];
                int VetorC[N];

                GerarVetor(VetorA,Tam,13);
                MostrarVetor(VetorA,Tam);

                printf("\n\n");

                GerarVetor(VetorB,Tam,20);
                MostrarVetor(VetorB,Tam);

                printf("\n\n");

                for(i=0;i<N;i++)
                {
                    if(VetorA[i] > VetorB[i])
                    {
                        VetorC[i] = 1;
                    }
                    if(VetorA[i] < VetorB[i])
                    {
                        VetorC[i] = -1;
                    }
                    if(VetorA[i] == VetorB[i])
                    {
                        VetorC[i] = 0;
                    }
                    printf("%d\t",VetorC[i]);
                }
                printf("\n________________________________________________________________________________");

                break;
            }
            case '6':
            {
                printf("\n               Pressione Enter para finalizar...\n");
                exit(0);
            }
            default:
            {
                printf("                 Opcao Inválida!");
            }
        }

        printf("\n");
        printf("\n                       Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
