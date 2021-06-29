#include <stdio.h>
#include <stdlib.h>
/*

*/
int main (void)
{
    char Continuar;
    int Num;
    int Qtdeprimos;
    int Somaprimos;
    float Mediaprimos;
    int Cont;
    int Aux;
    int Qtdedivisores;

    do// repetir a exec=ução do programa
    {
        //incicializar variaveis a cada execução
        Somaprimos=0;
        Qtdeprimos=0;
        do//validar a entrada para que seja numero > 0.
        {
            printf("Informe a quantidade de primos a serem mostrados: ");
            scanf("%d",&Num);
            if(Num < 0)
            {
                printf("informe um numero positivo\n");
            }
            else if (Num == 0)
            {
                printf("Programa sera finalizado.\n");
                exit(0);
            }
        }while(Num < 0);

        if (Num == 1)
        {
            printf("1\t",Num);
            Somaprimos = 1;
            Qtdeprimos = 1;
        }
        else if (Num ==2)
        {
            printf("1\t2\t",Num);
            Somaprimos = 1 + 2;
            Qtdeprimos = 2;
        }
        else if (Num == 3)
        {
            printf("1\t2\t3\t",Num);
            Somaprimos = 1 + 2 + 3;
            Qtdeprimos = 3;
        }
        else // mostrar mais de 3 primos
        {
            printf("1\t2\t3\t",Num);
            Somaprimos = 1 + 2 + 3;
            Qtdeprimos = 3;
            Aux=5;//contera o numero a ser testado se primo

            do
            {
                Qtdedivisores=0;
                for(Cont=2;Cont<=Aux/2;Cont++)
                {
                    if(Aux % Cont == 0)
                    {
                        Qtdedivisores++;
                        break;//sair do for
                    }
                }
                if (Qtdedivisores == 0)
                {
                    printf("%d\t",Aux);
                    Qtdeprimos++;
                    Somaprimos = Somaprimos + Aux;
                }
                Aux++;

            }while(Qtdeprimos < Num);

            if (Qtdeprimos >0)
            {
                Mediaprimos = (float)Somaprimos/Qtdeprimos;
                printf("\nA Media dos primos: %.2f\n",Mediaprimos);
            }
        }
            printf("Executar novamente (S/s para sim)");
            fflush(stdin);
            scanf("%c",&Continuar);

    }while(Continuar == 'S' || Continuar == 's');

    system("pause");
}
