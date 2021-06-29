#include <stdio.h>
#include <stdlib.h>
/*
Ler um caractere que indica uma opção:
F/f para fatorial
P/p para primo.
Se o usuário informar um caractere válido ler o número e calcular o fatorial ou
verificar se o mesmo é primo dependendo da opção escolhida.
Finalizar quando informado um caractere diferente de F/f/P/p
*/
int main (void)
{
    char Pri,Fat=1,Car,Continuar;
    int Num,Cont,Qtdivi=0;

    do
    {
        system("cls");
        Qtdivi=0;
        fflush(stdin);

        printf("\nPara Calculo Fatorial [F / f] e Para Calculo dos Primos[P / p]: ");
        scanf("%c",&Car);

        if(Car == 'F' || Car =='f')
        {
            printf("---[___________________________CALCULO DO FATORIAL__________________________]---\n\n");

            printf("Informe Um Numero: ");
            scanf("%d",&Num);
            printf("\n");

            for(Cont=1;Cont<=Num;Cont++)
            {
                Fat=Fat*Cont;
            }

            printf("%d! = %d \n ",Num,Fat);

             //5! => 5 * 4 * 3 * 2 * 1 = 120

        }
        else if(Car == 'P' || Car =='p')
        {
            printf("---[____________________________CALCULO DOS PRIMOS__________________________]--\n\n");

            printf("Informe Um Numero: ");
            scanf("%d",&Num);
            printf("\n");

            for(Cont=2;Cont<=Num/2;Cont++)
            {

                if(Num % Cont == 0)
                {
                    Qtdivi++;
                    break;
                }
            }
            if(Qtdivi == 0)
            {
                printf("O Numero e Primo!");
                printf("\n");
            }
            else
            {
                printf("O Numero Nao e Primo!");
                printf("\n");
            }

        }
        else
        {
            printf("\n");
            printf("Somente F/f ou P/p !!! \n");
        }


    printf("\nPara Continuar a Calcular (S / s): ");
    fflush(stdin);
    scanf("%c",&Continuar);
    }while(Continuar == 'S' || Continuar == 's');
    printf("\n");

    system("pause");
}
