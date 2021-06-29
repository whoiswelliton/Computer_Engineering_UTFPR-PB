#include <stdio.h>
#include <stdlib.h>

/*
) Ler três nomes com até 50 caracteres. Armazená-los em uma matriz. Em seguida, verificar se há dois espaços
sucessivos em branco retirá-los. Armazenar as strings sem espaços em branco consecutivos no mesma matriz.
 Atenção: É indispensável finalizar a string colocando '\0' como último caractere.
Exemplo:
Alunos     de     Computação
Engenharia         de     Computação           da UTFPR
Engenharia,  engenharia.

Resulta:
Alunos de Computação
Engenharia de Computação da UTFPR
Engenharia, engenharia.

*/
int main (void)
{
    int i,j;
    char Continuar,Matriz[3][50];
    do
    {
        i=0;
        j=0;

        for(i=0;i<3;i++)
        {
            system("cls");
            printf("\n_______________________________________________________________________________\n");
            printf("Informe um Nome: ");
            fflush(stdin);
            scanf("%s",&Matriz[i][50]);

        }

        for(i=0;i<3;i++)
        {
            for(i=0;i<50;i++)
            {
                while(Matriz[i][j] != '\0')
                {
                    if(Matriz[i][j] != ' ')
                    {
                        printf("%c",Matriz[i][j]);
                    }
                    else if(Matriz[i][j-1] == ' ');
                    {
                        printf("%c",Matriz[i][j]);
                    }
                }
            }
        }


        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
