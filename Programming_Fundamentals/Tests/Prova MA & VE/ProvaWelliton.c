#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


void Primos (int Num)
{
    int i=0,j=0;
    int Vet2[10];

        for(j=2;i<=Num/2;i++)
        {
            if(Num % i == 0)
            {
                return(Num);
                break;
            }
        }


}


void Fatorial (int Vet[],int Tam)
{
    int i=0;
    int Fat;

    for(i=0;i<=Tam;i++)
    {
        Fat=Fat*Vet[i];
    }
    printf("%d\t",Fat);
    return(Fat);
}


void GerarVetor (int Vet[],int Tam,int Limite)
{
    int i=0;

    (srand(time(NULL)));

    for(i=0;i<Tam;i++)
    {
        Vet[i] = rand() % (Limite +1);
        printf("%d\t",Vet[i]);
    }

}


int main (void)
{
    char Continuar,Opcao,String[15],Substring[15];
    int Vet[20],Vet2[10],Vet3[10],VetI[20],Rep[20],VetP[10],i,j,k,Tam,Limite,Retorno,Num;


    do
    {
        system("cls");

        printf("\n----------------------------[Escolha Qual Exercicio]----------------------------\n");
        printf(" 1 - Exercicio 1\n");
        printf(" 2 - Exercicio 2\n");
        printf(" 3 - Exercicio 3\n\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("                                   Opcao: ");
        fflush(stdin);
        scanf("%c",&Opcao);
        system("cls");

        switch(Opcao)
        {
            case'1':
            {
                i=j=k=0;
                Limite = 10;
                Tam = 20;

                printf("Vetor\n\n");
                GerarVetor (Vet,20,10);

                Vet[i] = Vet2[j];

                printf("\nValores Repetidos\n\n");

                for(i=0;i<20;i++)
                {
                    for(j=0;j<20;j++)
                    {
                        if(Vet[i] == Vet2[j])
                        {
                            k++;
                            if(k > 1)
                            {
                                Rep[i]=Vet[i];
                            }

                        }
                    }

                }
                printf("%4d",Rep[i]);


                break;
            }
            case '2':
            {
                printf("Informe uma Frase: ");
                fflush(stdin);
                gets(String);

                printf("Informe uma Palavra: ");
                fflush(stdin);
                gets(Substring);

                i=j=k=0;
                while(Substring[j] != '\0')
                {
                    k++;
                }
                while(String[i] != '\0' && Substring[j] != '\0')
                {
                    for(j=0;j<k;j++)
                    {
                        if(Substring[j] == String[i])
                        {
                            printf("\n\nRetorno: S");
                            printf("\nA Substring faz parte da String");
                        }
                        else
                        {
                            printf("\n\nRetorno: N");
                            printf("\nA Substring nao faz parte da String");
                        }
                    }

                }

                break;
            }
            case '3':
            {
                i=j=0;
                Limite = 30;
                Tam = 10;

                printf("Vetor 1 \n\n");
                GerarVetor (Vet,10,30);

                printf("Vetor Invertido \n\n");


                for(i=9;i>0;i--)
                {
                    if(i >= 5)
                    {
                        Vet2[i] = Vet[i];
                    }
                }
                for(i=9;i>=0;i--)
                {
                    if(i < 5)
                    {
                        Vet3[i] = Vet[i];
                    }
                }
                VetI[i] = Vet2[i];
                VetI[i] = Vet3[i];

                printf("%d\t",VetI[i]);

                j=0;
                for(i=0;i<10;i++)
                {
                    if(Vet[i] < 10)
                    {
                        Vet[i] = Num;

                        Fatorial(Vet,Tam);

                        Retorno = Primos(Num);
                        printf("%d\t",Retorno);
                    }
                }

                break;
            }
        }

        printf("\n\nPara Executar Novamente(S/s para sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');
}
