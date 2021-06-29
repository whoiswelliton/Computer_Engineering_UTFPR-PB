#include <stdio.h>
#include <stdlib.h>
/*Ler dois valores numéricos e apresentar a diferença entre eles. A diferença sempre é positiva,
portanto, o menor é subtraído do maior não importando a ordem em que os números são informados.
*/

int main (void)

{
    int Num1,Num2;

    printf("Informe o primeiro numero: ");
    scanf("%d",&Num1);
    printf("Informe o segundo numero: ");
    scanf("%d",&Num2);

    if (Num1 >= Num2)
    {
        Num1 = Num1-Num2;
    }
    else
    {
        Num1 = Num2-Num1;
    }

    printf(" A diferença e de: %d\n",Num1);

    system("pause");
}
