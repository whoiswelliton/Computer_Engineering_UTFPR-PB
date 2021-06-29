# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# include<math.h>

int main(void)
{
    char Continuar;
    int Vet[20],Repetidos[10],i,j,k,l;

    do
    {
        system("cls");
        l=0;
        srand(time(NULL));
        printf("Vetor gerado: ");
        for(i=0; i<20; i++)
        {
            Vet[i] = rand()%11;
            printf("%d\t",Vet[i]);``
        }

        for(i=0; i<20; i++)//percorrer o vetor
        {
            for(j=i+1;j<20; j++)//percorrer do indice do elemento sendo verificado até o final do vetor
            {
                if(Vet[i] == Vet[j])
                {
                    for(k=0;k<l;k++)//verificar se o valor encontrado como repetido já está armazenado no vetor de repetidos
                    {
                        if(Vet[i] == Repetidos[k])
                        {
                            break;//já está armazendo
                        }
                    }
                    if(k==l)//chegou ao final dos vetores de repetidos e não foi encontrado valor igual
                    {
                        Repetidos[l] = Vet[i];
                        l++;
                    }
                }
            }
        }
        printf("\n\nValores repetidos: ");
        for(i=0;i<l;i++)
        {
            printf("%d\t",Repetidos[i]);
        }

        printf("\nExecutar novamente: ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 'S' || Continuar == 's');
}
