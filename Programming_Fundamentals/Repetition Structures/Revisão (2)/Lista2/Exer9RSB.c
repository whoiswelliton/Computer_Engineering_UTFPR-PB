#include <stdio.h>
#include <stdlib.h>
/*
Ler caracteres. Se informado A ou a. Ler um número inteiro e se o mesmo possui até
3 dígitos invertê-lo (mostrar como um 'nico dígito e não como três dígitos separados.
Se informado B ou b ler um número float e separar a parte inteira da decimal.
Permanecer em execução enquanto informado A/a/B/b como caractere.
*/
int main (void)
{
    char Car,Continuar;
    int Num,Inver,C,D,U;
    float Num2,Decimal,Inteira;

    do
    {
        system ("cls");
        fflush(stdin);
        printf(" -> Informe se deseja Calculo (A/a) ou (B/b): ");
        scanf("%c",&Car);

        if(Car == 'A' || Car == 'a')
        {
            printf("\n");
            printf("__________________________________(CALCULO I)___________________________________\n\n");
            printf("Informe um numero de ate 3 digitos: ");
            scanf("%d",&Num);

            C = Num / 100;
            D = (Num % 100)/10;
            U = Num % 10;

            Inver= U*100 + D*10 + C;

            printf("\n");
            printf("Numero Invertido = %d \n",Inver);
            printf("________________________________________________________________________________\n\n");

        }
        else if(Car == 'B' || Car == 'b')
        {
            printf("\n");
            printf("__________________________________(CALCULO II)__________________________________\n\n");
            printf("Informe um numero: ");
            scanf("%f",&Num2);

            Decimal = Num2 - (int)Num2;
            Inteira = Num2 - Decimal;

            printf("\n");
            printf("Parte Inteira = %.2f \n",Inteira);
            printf("Parte Decimal = %.2f \n",Decimal);
            printf("________________________________________________________________________________\n\n");
        }

    printf("\n");
    printf("Para Executar Novamente (S/s): ");
    fflush(stdin);
    scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');

    printf("\n");
    system("pause");
}
