# include<stdio.h>
# include<stdlib.h>

char FuncaoSubstring(char String[], char Substring[]);

int main(void)
{
    char String[51],Sub[16],Continuar,Retorno;

    do
    {
        system("cls");

        printf("Digite uma String: ");
        fflush(stdin);
        gets(String);

        printf("Digite uma SubString: ");
        fflush(stdin);
        gets(Sub);

        Retorno = FuncaoSubstring(String,Sub);
        if(Retorno == 's')
        {
            printf("A Substring faz parte da string");
        }
        else
        {
            printf("A Substring nao faz parte da string");
        }

        printf("\nExecutar novamente: ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 'S' || Continuar == 's');
}

char FuncaoSubstring(char String[], char Substring[])
{
    char Retorno;
    int i=0,j,Tam=0;

    while(Substring[Tam] != '\0')
    {
        Tam++;
    }

    while(String[i]!='\0')
    {
        if(String[i] == Substring[0])//se o primeiro caractere da substring é igual ao conteúdo da string no indice i
        {
            j=0;
            while(Substring[j] != '\0')
            {
                if(String[i] != Substring[j])
                {
                    break;
                }
                i++;
                j++;
            }
        }
        if(j==Tam)
        {
            return('s');
        }
        i++;
    }
    return('n');
}
