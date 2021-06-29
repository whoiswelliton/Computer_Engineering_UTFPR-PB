#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

int main (void)
{
    char Continuar,Opcao,Nome[50],Senha[6],Senha2[6],Texto[50],Frase[50],Frase2[10],Tam[20];
    int i,qto,Qttent,Cont,Cont2,VetVogais[5],j,Vet[5];

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
                system("cls");
                i=0;
                do
                {
                    qto=0;
                    printf("\nInforme um Nome Com ate 50 letras: ");
                    fflush(stdin);
                    gets(Nome);

                    i=0;//inicializar denovo para percorrer a string
                    while(Nome[i] != '\0')
                    {
                        if(Nome[i]== 'o')
                        {
                            qto++;
                        }
                        i++;
                    }

                    if(Nome[0] == 'a')
                    {
                        printf("\n %s \n",Nome);
                    }
                    else
                    {
                        printf("O Nome tem %d Caracteres 'o'\n",qto);
                    }

                }while(Nome[0] != '0');

                break;
            }
            case 'B':
            {
                    system("cls");
                    Qttent=0;
                    i=Cont=Cont2=0;

                    printf("\n________________________________________________________________________________\n");
                    printf("\n\n\n\n\n\n\n\n                      CRIE UMA SENHA COM ATE 6 DIGITOS: ",144);
                    fflush(stdin);
                    gets(Senha);
                    printf("\n\n\n\n\n\n\n\n\n_________________________________%c Press Enter %c________________________________\n",186,186);
                    getchar();
                    system("cls");

                        while(Senha[Cont] != '\0')
                        {
                            Cont++;
                        }
                        do
                        {
                            i=0;
                            printf("\n                                Informe Sua Senha: ");
                            fflush(stdin);
                            gets(Senha2);

                            while(Senha2[i] != '\0')
                            {
                                if(Senha[i] != Senha2[i])
                                {
                                   i++;
                                   break;
                                }
                                i++;
                            }

                            if(i == Cont)
                            {
                                printf("\n Senha Correta\n ");
                                break;

                            }
                            else
                            {
                                printf("\n Senha Incorreta\n ");

                            }

                            if(Qttent == 2)
                            {
                                system("cls");
                                printf("\n________________________________________________________________________________\n");
                                printf("\n\n               Senha Bloqueada! Ultrapassou o limite de Tentativas.\n");
                                printf("\n\n________________________________________________________________________________\n");
                            }
                            Qttent++;

                        }while(Qttent< 3);

                break;
            }
            case 'C':
            {
                system("cls");
                printf("\n________________________________________________________________________________\n");
                printf("\n\n\n\n\n\n\n\n         Informe um Nome Com ate 50 letras: ");
                fflush(stdin);
                gets(Nome);
                printf("\n\n\n\n\n\n\n\n\n_________________________________%c Press Enter %c________________________________\n",186,186);
                getchar();

                VetVogais[0]=0;
                VetVogais[1]=0;
                VetVogais[2]=0;
                VetVogais[3]=0;
                VetVogais[4]=0;

                system("cls");

                for(i=0;i<5;i++);
                {
                    VetVogais[i]=0;
                }
                i=0;

                while(Nome[i] != '\0')
                {

                    if(Nome[i] == 'a')
                    {
                        VetVogais[0]++;
                    }
                    else if(Nome[i] == 'e')
                    {
                        VetVogais[1]++;
                    }
                    else if(Nome[i] == 'i')
                    {
                        VetVogais[2]++;
                    }
                    else if(Nome[i] == 'o')
                    {
                        VetVogais[3]++;
                    }
                    else if(Nome[i] == 'u')
                    {
                        VetVogais[4]++;
                    }
                    i++;
                }

                printf("  %s \n",Nome);
                printf("\n Vogal      %c       Quantidade\n",175);
                printf("  A/a  	     =         %d\n",VetVogais[0]);
                printf("  E/e  	     =         %d\n",VetVogais[1]);
                printf("  I/i  	     =         %d\n",VetVogais[2]);
                printf("  O/o  	     =         %d\n",VetVogais[3]);
                printf("  U/u  	     =         %d\n",VetVogais[4]);

                break;
            }
            case 'D':
            {
                i=j=0;
                system("cls");

                printf("Crie um Texto: ");
                fflush(stdin);
                gets(Texto);


                while(Texto[i] != '\0')
                {

                    if(Texto[i] == 'a')
                    {
                        Vet[j++]=1;
                    }
                    else if(Texto[i] == 'e')
                    {
                        Vet[j++]=2;
                    }
                    else if(Texto[i] == 'i')
                    {
                        Vet[j++]=3;
                    }
                    else if(Texto[i] == 'o')
                    {
                        Vet[j++]=4;
                    }
                    else if(Texto[i] == 'u')
                    {
                        Vet[j++]=5;
                    }
                    i++;
                }

                printf("\n");
                MostrarVetor(Vet,j);
                break;
            }
            case 'E':
            {
                system("cls");

                printf("\nDigite uma Frase: ");
                fflush(stdin);
                gets(Frase);

                printf("\nCaracteres no indice Par\n\n");
                i=0;
                while(Frase[i] != '\0')
                {
                    if(i % 2 == 0)
                    {
                        printf("%c\t",Frase[i]);
                    }
                    i++;

                }
                i=0;
                printf("\nCaracteres no indice Impar\n\n");
                while(Frase[i] != '\0')
                {
                    if(i % 2 != 0)
                    {
                        printf("%c\t",Frase[i]);
                    }
                    i++;
                }
                i=0;
                printf("\nPrimeiro caractere de cada palavra\n\n");
                while(Frase[i] != '\0')
                {
                    if(Frase[i] == ' ' && Frase[i+1] != ' ')
                    {
                        printf("%c  ",Frase[i+1]);
                    }
                    i++;
                }
                i=0;
                printf("\nUltimo caractere de cada palavra\n\n");
                while(Frase[i] != '\0')
                {
                    if(Frase[i] == ' ' && Frase[i-1] != ' ')
                    {
                        printf("%c  ",Frase[i-1]);
                    }
                    i++;
                }
                if(Frase[i-1] != ' ')
                {
                    printf("%c  ",Frase[i-1]);
                }
                i=0;
                printf("\nPrimeira Palavra\n\n");

                while(Frase[i] != ' ')
                {
                    Frase2[i]=Frase[i];
                    i++;
                }
                Frase2[i]='\0';
                i=0;
                while(Frase2[i] != '\0')
                {
                    printf("%c  ",Frase2[i]);
                    i++;
                }

                break;
            }
            case 'F':
            {
                system("cls");
                Cont=i=0;

                printf("\nDigite uma Frase: ");
                fflush(stdin);
                gets(Frase);

                while(Frase[i] != '\0')
                {
                    if(Frase[i] != ' ')
                    {
                        Cont++;
                    }
                    i++;
                }

                printf("\nQuantidade de caracteres sem os espa%cos : %d ",135,Cont);
                printf("\nQuantidade de caracteres com os espa%cos : %d ",135,i);

                break;
            }
            case 'G':
            {
                system("cls");
                Cont=0;

                printf("\nInforme um texto com at%c 50 caracteres: ",130);
                fflush(stdin);
                gets(Texto);

                 while(Texto[Cont] != '\0')
                 {
                     Cont++;
                 }
                 for(Cont;Cont>=0;Cont--)
                 {
                     printf("\n Ao Contrário \n");
                     printf("%c",Texto[Cont]);
                 }

                break;
            }
            case'H':
            {
                system("cls");
                Cont=0;

                printf("\nInforme uma Frase com at%c 15 caracteres: ",130);
                fflush(stdin);
                gets(Frase);

                printf("\n Frase na Vertical \n");
                 while(Frase[Cont] != '\0')
                 {
                     printf("   %c\n",Frase[Cont]);
                     Cont++;
                 }


                break;
            }
            case'I':
            {
                system("cls");
                i=0;

                printf("\nInforme uma Frase: ");
                fflush(stdin);
                gets(Frase);
                while(Frase[i] != ' ')
                {
                    Frase2[i]=Frase[i];
                    i++;
                }
                Frase2[i]='\0';
                i=0;
                while(Frase2[i] != '\0')
                {
                    printf("%c",Frase2[i]);
                    i++;
                }

                break;
            }
            case'J':
            {
                system("cls");
                Cont=Cont-1;
                i=0;

                printf("\nInforme uma Frase com at%c 20 caracteres: ",130);
                fflush(stdin);
                gets(Frase);

                while(Frase[Cont] != '\0')
                {
                    if(Frase[Cont] != ' ')
                    {
                        Frase2[i]=Frase[Cont];
                        i++;
                    }
                    Cont++;
                }
                Frase[i]='\0';
                i=0;
                while(Frase2[i] != '\0')
                {
                    if(Frase2[i] != Frase2[Cont-i])
                    {
                        break;
                    }
                    i++;
                }
                if(i==Cont)
                {
                    printf(" Yes Brother!");
                }


                break;
            }
            case'K':
            {

                break;
            }
        }
        printf("\n\n________________________________________________________________________________\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
