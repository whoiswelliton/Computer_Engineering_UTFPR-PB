# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# include<math.h>

int Fatorial(int Num);
int Primo(int Num);

int main (void)
{
    char Continuar;
    int Vet[10],Fatoriais[10],Primos[10],i,j,Aux,Retorno;

    do
    {
        system("cls");
        srand(time(NULL));

        for(i=0;i<10;i++)
        {
            Aux = rand()%31;
            //verificar se o valor já está no vetor. Ideia percorrer o vetor e verificar se o valor sorteado já está armazenado
            for(j=0;j<i;j++)
            {
                if(Vet[j] == Aux)//o valor sortedo já está armazenado no vetor
                {
                    i--;//o valor para o indice i atual deve ser gerado novamente
                    break;
                }
            }
            if (j==i)//percorreu todos os indices do vetor de repetidos e o valor não está armazenado
            {
                Vet[j] = Aux;
            }
        }

        printf("Conteúdo do vetor gerado:\n");
        for(i=0;i<10;i++)
        {
            printf("%d\t",Vet[i]);
        }

        do
        {
            Retorno=0;
            for(i=0;i<10;i++)
            {
                for(Aux=i+1; Aux<10;Aux++)
                {
                    if(Vet[i] == Vet[Aux])
                    {
                        Vet[i] = rand()%31;
                        Retorno++;
                    }
                }
            }
        }while(Retorno>0);

        for(i=0;i<5;i++)
        {
            Aux = Vet[9-i];
            Vet[9-i] = Vet[i];
            Vet[i] = Aux;
        }

        printf("\Vetor com valores invertidos:\n");
        for(i=0;i<10;i++)
        {
            printf("%d\t",Vet[i]);
        }

        j=0;
        for(i=0;i<10;i++)
        {
            if(Vet[i] <10)
            {
                Fatoriais[j] = Fatorial(Vet[i]);
                j++;
            }
        }
        printf("\Fatorial: \n");
        for(i=0;i<j;i++)
        {
            printf("%d\t",Fatoriais[i]);
        }

        j=0;
        for(i=0;i<10;i++)
        {
            Retorno = Primo(Vet[i]);
            if(Retorno == 0)
            {
                Primos[j] = Vet[i];
                j++;
            }
        }
        printf("\nPrimos:\n");
        for(i=0;i<j;i++)
        {
            printf("%d\t",Primos[i]);
        }

        printf("\nExecutar novamnete: ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 'S' || Continuar == 's');
}

int Fatorial(int Num)
{
    int i,Fat=1;
    for(i=Num;i>1;i--)
    {
        Fat=Fat*i;
    }
    return(Fat);
}

int Primo(int Num)
{
    int i,Div=0;
    for(i=2; i<Num/2; i++)
    {
        if(Num % i == 0)
        {
            Div++;
            break;
        }
    }
    if(Num == 0)
    {
        Div = 1;//para não constar zero como primo.
    }
    return(Div);
}
