#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char Opcao,Continuar;
    int Cont,Cont2,Cont3,Num,Qtlinhas=0,Qtfor=0;

    do
    {
        system("cls");
        int Qtfor=0;

        printf("________________________________________________________________________________\n");
        printf("                      PIRAMIDES GEOMETRICAS COM NUMEROS                         ");
        printf("________________________________________________________________________________\n");
        printf("                              Programa - 1\n");
        printf("                              Programa - 2\n");
        printf("                              Programa - 3\n");
        printf("                              Programa - 4\n");
        printf("                              Programa - 5\n");
        printf("                              Programa - 6\n");
        printf("                              Programa - 7\n");
        printf("                              Programa - 8\n");
        printf("                              Programa - 9\n");
        printf("                              Sair     - 10\n");
        printf("________________________________________________________________________________\n\n");
        printf("Opcao: ");
        scanf("%c",&Opcao);

        printf("\n");

        printf("Informe um Numero: ");
        scanf("%d",&Num);

        printf("\n");

        switch(Opcao)
        {
            case'1':
            {
                for(Cont=1;Cont<=Num;Cont++)
                {
                    Qtfor=0;

                    for(Cont2=1;Qtfor<Num;Cont2++)
                    {
                        Qtfor++;

                        printf("   %d  ",Cont2);
                    }
                    printf("\n");
                }

                break;
            }
            case'2':
            {
                for(Cont=1;Cont<=Num;Cont++)
                {
                    Qtfor++;

                    for(Cont2=1;Cont2<=Qtfor;Cont2++)
                    {
                        printf("   %d  ",Cont);
                    }
                    printf("\n");
                }

                break;
            }
            case'3':
            {
                for(Cont=1;Cont<=Num;Cont++)
                {
                    Qtfor++;

                    for(Cont2=1;Cont2<=Qtfor;Cont2++)
                    {
                        printf("   %d  ",Cont);
                    }
                    printf("\n");
                }
                for(Cont=Num-1;Cont>=1;Cont--)
                {
                    Qtfor--;

                    for(Cont2=Qtfor;Cont2>=1;Cont2--)
                    {
                        printf("   %d  ",Cont);
                    }
                    printf("\n");
                }
                break;
            }
            case'4':
            {
                for(Cont=1;Cont<=Num;Cont++)
                {
                    Qtfor=0;

                    for(Cont2=1;Qtfor<Num;Cont2++)
                    {
                        Qtfor++;

                        printf("   %d  ",Cont);
                    }
                    printf("\n");
                }
                break;
            }
            case'5':
            {
                for(Cont=1;Cont<=Num;Cont++)
                {
                    Qtfor++;

                    for(Cont2=1;Cont2<=Num;Cont2++)
                    {

                        if(Cont2 <= Cont)
                        {
                            printf("   %d  ",Cont);
                        }
                        else
                        {
                            printf("   *  ");
                        }
                    }
                    printf("\n");
                }

                break;
            }
            case'6':
            {
                for(Cont=1;Cont<=Num;Cont++)
                {
                    Qtfor++;

                    for(Cont3=Cont+1;Cont3<=Num;Cont3++)
                    {
                        printf("   ");
                    }
                    for(Cont2=1;Cont2<=Qtfor;Cont2++)
                    {
                       printf("%3d",Cont);
                    }
                    printf("\n");
                }
                for(Cont=Num-1;Cont>=1;Cont--)
                {
                    Qtfor--;

                    for(Cont3=Num;Cont3>=Cont+1;Cont3--)
                    {
                        printf("   ");
                    }
                    for(Cont2=Qtfor;Cont2>=1;Cont2--)
                    {
                        printf("%3d",Cont);
                    }

                    printf("\n");
                }
                break;
            }
            case'7':
            {
                for(Cont=1;Cont<=Num;Cont++)
                {
                    Qtfor++;

                    for(Cont2=1;Cont2<=Qtfor;Cont2++)
                    {
                        printf("   %d  ",Cont2);
                    }
                    printf("\n");
                }

                break;
            }
            case'8':
            {
                for(Cont=1;Cont<=Num;Cont++)
                {
                    Qtfor++;

                    for(Cont2=Cont+1;Cont2<=Num;Cont2++)
                    {
                        printf("   ");
                    }
                    for(Cont2=1;Cont2<=Qtfor;Cont2++)
                    {
                        printf("%3d",Cont);
                    }
                    printf("\n");
                }

                break;
            }
            case'9':
            {
                for(Cont=1;Cont<=Num;Cont++)
                {
                    Qtfor++;

                    for(Cont2=1;Cont2<=Qtfor;Cont2++)
                    {
                        printf("%3d",Cont);
                    }
                    for(Cont2=Cont+1;Cont2<=Num;Cont2++)
                    {
                        printf("   ");
                    }
                    for(Cont3=Cont+1;Cont3<=Num;Cont3++)
                    {
                        printf("   ");
                    }
                    for(Cont2=1;Cont2<=Qtfor;Cont2++)
                    {
                        printf("%3d",Cont);

                    }
                    printf("\n");
                }

                break;
            }
            case'10':
            {
                printf("Aperte Enter para Sair...");
                exit(0);
            }
            default:
            {
                printf("Opcao Invalida!\n");
            }
        }

        printf("________________________________________________________________________________\n");
        printf("\nExecutar Novamente (S/s para Sim): ");
        printf("\n");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
