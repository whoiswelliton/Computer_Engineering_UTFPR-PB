#include <stdio.h>
#include <stdlib.h>
/*
Apresentar os números primos entre 0 e 100.
*/
int main (void)
{
    int Continuar;
    int Divi,Num;
    int Qtdivi;

     do
    {
        do
        {
            system("cls");
            printf("1\t2\t3\t");

            for(Num=5;Num<=100;Num++)
            {
                for(Divi=2;Divi<=Num/2;Divi++)
                {
                    Qtdivi=0;

                    if(Num % Divi ==0)
                    {
                        Qtdivi++;
                        break;
                    }
                }
                if(Qtdivi == 0)
                {
                    printf("%d\t",Num);
                }
            }

        }while(Num <100);

        printf("\nExecutar novamente (S/s para sim): ");
        getchar();
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');




    system("pause");
}


