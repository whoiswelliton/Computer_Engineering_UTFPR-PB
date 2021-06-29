#include<stdio.h>
#include<stdlib.h>

int main(void)

{
    float sal, aumento, desconto, salau, salfinal;
    int reais, centavos;

    printf("informe o salario: ");
    scanf("%f",&sal);
    printf("informe o aumento: ");
    scanf("%f",&aumento);
    printf("informe o desconto: ");
    scanf("%f",&desconto);

    salau=(sal+(sal*aumento/100));
    salfinal=(salau-(salau*desconto/100));
    reais=(int)salfinal;
    centavos=(salfinal-reais)*100;

    printf("o seu novo salario sera de %d reais e %d centavos",reais,centavos);
}
