#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"
#include "Funcoes.h"

int main (void)
{
    char Continuar,Opcao,Nome[50],Senha1[7],Senha2[7],String[50],String2[50],VetVogais[5];
    int qtd,i,j,k,VetVogais2[20];

    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf(" A - Exerc%ccio 1\n",161);
        printf(" B - Exerc%ccio 2\n",161);
        printf(" C - Exerc%ccio 3\n",161);
        printf(" D - Exerc%ccio 4\n",161);
        printf(" E - Exerc%ccio 5\n",161);
        printf(" F - Exerc%ccio 6\n",161);
        printf(" G - Exerc%ccio 7\n",161);
        printf(" H - Exerc%ccio 8\n",161);
        printf(" I - Exerc%ccio 9\n",161);
        printf(" J - Exerc%ccio 10\n",161);
        printf(" K - Exerc%ccio 11\n",161);
        printf("_______________________________________________________________________________\n");

        printf("\nDeseja o Exerc%ccio: ",161);
        fflush(stdin);
        scanf("%c",&Opcao);

        switch(Opcao)
        {
            case 'A':
            {

                /*Ler um nome. Se o primeiro caractere for 'a' imprimir esse nome. Se não for 'a' contar quantos caracteres
                 'o' o nome possui. Repetir a leitura até que o usuário informe zero (0) como primeiro caractere do nome.*/
                 i=0;
                 system("cls");
                 do
                 {
                    qtd=0;
                    i=0;
                    printf("Informe um Nome: ");
                    fflush(stdin);
                    gets(Nome);

                    while(Nome[i] != '\0')
                    {
                        if(Nome[i] == 'o')
                        {
                            qtd++;
                        }
                        i++;
                    }

                    if(Nome[0] == 'a')
                    {
                        printf("\n %s \n",Nome);
                    }
                    else
                    {
                        printf("O Nome tem %d Caracteres 'o'\n",qtd);
                    }


                 }while(Nome[0] != '0');

               break;

            }
            case 'B':
            {
                /* Elaborar um programa que aceita e valida uma senha com 6 dígitos numéricos, que deve ser armazenada em
                uma string. O usuário tem três tentativas para acertar a senha, se ultrapassar esse limite, ele deve ser
                informado. O usuário também deve ser informado se ele acertou a senha em até três tentativas.*/
                qtd=0;
                i=0,j=0,k=0;

                system("cls");
                printf("Crie uma senha com ate 6 digitos: ");
                fflush(stdin);
                gets(Senha1);

                while(Senha1[j] != '\0')
                {
                    j++;
                }

                system("cls");

                printf("Digite sua senha: ");
                fflush(stdin);
                gets(Senha2);

                while(Senha2[i] != '\0')
                {
                    i++;
                }

                system("cls");

                if(j == i)
                {
                    while(Senha1[k] == Senha2[k] && Senha1[k] != '\0' )
                    {
                        k++;
                    }
                    if(k==j)
                    {
                        printf("Senha correta!");
                    }
                    else
                    {
                        printf("Senha Incorreta!");
                    }
                }
                else
                {
                    printf("Senha Incorreta!");
                }


               break;
            }
            case 'C':
            {
                /*Ler uma string, contar e exibir a quantidade de cada uma das vogais existentes nessa string.
                 Armazenar essas quantidades em um vetor. É indispensável armazenar a quantidade à medida que a string
                 é percorrida (algo como VetVogais[X]++ ou VetVogais[X] =  VetVogais[X] + 1). Portanto, o vetor que
                 armazena a quantidade de vogais deve ser inicializado com zero antes de ser utilizado. Mostrar os
                 resultados da seguinte forma.
                Vogal	        Quantidade
                ===================
                A/a		    5
                E/e		    0
                I/i		    1
                O/o		    2
                U/u		    0 */

                for(i=0;i<=5;i++)
                {
                    VetVogais[i] =0;
                }
                i=0;

                system("cls");

                printf("Informe uma string: ");
                fflush(stdin);
                gets(String);
                system("cls");

                while(String[i] != '\0')
                {
                    if(String[i] == 'a' || String[i] == 'A')
                    {
                        VetVogais[0]++;
                    }
                    else if(String[i] == 'e' || String[i] == 'E')
                    {
                        VetVogais[1]++;
                    }
                    else if(String[i] == 'i' || String[i] == 'I')
                    {
                        VetVogais[2]++;
                    }
                    else if(String[i] == 'o' || String[i] == 'O')
                    {
                        VetVogais[3]++;
                    }
                    else if(String[i] == 'u' || String[i] == 'U')
                    {
                        VetVogais[4]++;
                    }
                    i++;
                }

                printf("\nVogais:\n");
                printf("A/a = %d \n",VetVogais[0]);
                printf("E/e = %d \n",VetVogais[1]);
                printf("I/i = %d \n",VetVogais[2]);
                printf("O/o = %d \n",VetVogais[3]);
                printf("U/u = %d \n",VetVogais[4]);

               break;
            }
            case 'D':
            {
                /*  Ler um texto com até 50 caracteres. Percorrer esse texto e verificar quais caracteres são vogais.
                Criar um vetor armazenando o número da vogal correspondente e somente das vogais (1 para 'a', 2 para 'e' ...)
                .Para simplificar, considerar que serão informados somente caracteres minúsculos.
                Por exemplo:
                Informado o texto:
                Texto para verificacao de vogais
                Saída (vetor gerado):
                2  4  1  1  2  3  3   1  1   4   4  1  3*/

                i=0,j=0;
                system("cls");

                printf("Informe uma string: ");
                fflush(stdin);
                gets(String);

                while(String[i] != '\0')
                {
                    if(String[i] == 'a' || String[i] == 'A')
                    {
                        VetVogais2[j] = 1;
                        j++;
                    }
                    else if(String[i] == 'e' || String[i] == 'E')
                    {
                        VetVogais2[j] = 2;
                        j++;
                    }
                    else if(String[i] == 'i' || String[i] == 'I')
                    {
                        VetVogais2[j] = 3;
                        j++;
                    }
                    else if(String[i] == 'o' || String[i] == 'O')
                    {
                        VetVogais2[j] = 4;
                        j++;
                    }
                    else if(String[i] == 'u' || String[i] == 'U')
                    {
                        VetVogais2[j] = 5;
                        j++;
                    }
                    i++;
                }

                printf("\n\nVetor:\n");
                MostrarVetor(VetVogais2,j);

                break;
            }
            case 'E':
            {
                /*  Ler um texto (string):
                a) imprimir os caracteres na posição par;
                b) imprimir os caracteres na posição ímpar;
                c) mostrar somente o primeiro caractere de cada palavra, separados por dois espaços;
                d) mostrar somente o último caractere de cada palavra, separados por dois espaços;
                e) copiar a primeira palavra para outra string e mostrá-la, obrigatoriamente, com do while, caractere a
                caractere. É indispensável finalizar a string copiada, ou seja, colocar '\0' no final da mesma.
                Exemplo para “mostrar somente o primeiro caractere de cada palavra, separados por dois espaços”.
                Informado: “Os ótimos alunos da Universidade Tecnológica Federal do Paraná, câmpus Pato Branco.”
                Mostrado:
                “O  ó  a  d  U  T  F d  P c  P  B”*/


                i=0;
                system("cls");

                printf("Informe uma string: ");
                fflush(stdin);
                gets(String);

                system("cls");
                printf("\n\na)Pares:\n");
                while(String[i] != '\0')
                {
                    if(i % 2 == 0)
                    {
                        printf("%c ",String[i]);
                    }
                    i++;
                }

                printf("\n\nb)Impares:\n");
                i=0;
                while(String[i] != '\0')
                {
                    if(String[i] % 2 != 0)
                    {
                        printf("%c ",String[i]);
                    }
                    i++;
                }
                printf("\n\nc)Primeiro Caractere:\n");

                if(String[0] != ' ')
                {
                    printf("%c  ",String[0]);
                }
                i=1;
                while(String[i] != '\0')
                {
                    if(String[i] == ' ' && String[i-1] != ' ')
                    {
                        printf("%c  ",String[i-1]);
                    }
                    i++;
                }

                i=0;
                printf("\n\nd)Ultimo Caractere:\n");

                while(String[i] != '\0')
                {
                    if(String[i] != ' ' && String[i+1] == ' ')
                    {
                        printf("%c  ",String[i]);
                    }
                    i++;
                }
                i=0;
                printf("\n\ne)Primeira Palavra:\n");

                while(String[i] != ' ')
                {
                    String2[i] = String[i];
                    i++;
                }
                String2[i] = '\0';

                MostrarVetorChar(String2);

                break;
            }

            case 'F':
            {
                /* Ler uma string, contar quantos caracteres a mesma possui, incluindo espaços e  contar quantos caracteres
                não incluindo espaços. */

                i=0,j=0,k=0;

                printf("\nInforme uma String: ");
                fflush(stdin);
                gets(String);

                while(String[i] != '\0')
                {
                    j++;
                    i++;
                }
                i=0;
                while(String[i] != '\0')
                {
                    if(String[i] != ' ')
                    {
                        k++;
                    }
                    i++;
                }


                printf("\n\nA String Tem %d caracteres.\n",j);
                printf("\n\nA String Tem %d caracteres fora os espacos.\n",k);


            }

            case 'G':
            {
                /*Ler um texto imprimi-lo de trás pra frente.
                 Sugestão: contar quantos caracteres a string possui (tamanho). Para contar os caracteres percorrer a
                 string até encontrar ‘\0’que indica final da string. Fazer uma função para contar o tamanho de uma
                 string.*/
                i=0,j=0;

                printf("\nInforme uma String: ");
                fflush(stdin);
                gets(String);

                while(String[i] != '\0')
                {
                    j++;
                    i++;
                }

                for(i=j;i>=0;i--)
                {
                    printf("%c ",String[i]);
                }

                break;
            }

            case 'H':
            {
                /*Ler uma frase e imprimir a frase na vertical com uma palavra por linha.*/
                i=0;

                printf("\nInforme uma String: ");
                fflush(stdin);
                gets(String);

                while(String[i] != '\0')
                {
                    printf("%c",String[i]);
                    if(String[i] == ' ' || String[i] == '  ')
                    {
                        printf("\n");
                    }
                    i++;
                }

            }
            case 'I':
            {

                i=0;
                printf("\nInforme uma String: ");
                fflush(stdin);
                gets(String);

                while(String[i] != ' ')
                {
                    String2[i] = String[i];
                    i++;
                }
                String2[i] = '\0';
               printf("%s",String2);

            }
            case 'J':
            {
                printf("\nInforme uma Palavra: ");
                fflush(stdin);
                gets(String);

                while(String[i] != '\0')
                {
                    j++;
                }
                while(String[i] != '\0')
                {

                    if([i] == (j-1-i))
                    {
                        printf("\nA palavra/frase contem um palindromos.\n");
                    }
                    else
                    {
                        printf("\nA palavra/frase nao contem um palindromos.\n");
                    }
                    i++;
                }

                break;
            }
        }

    printf("\n\n________________________________________________________________________________\n");
    printf("\n                           Executar Novamente (S/s para Sim): ");
    fflush(stdin);
    scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}

