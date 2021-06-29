#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Fazer um algoritmo para ler o salário de uma pessoa, o percentual de aumento e o percentual de descontos.
Os descontos são informados em percentual e incidem sobre o salário com aumento.
Calcular o novo salário e mostrá-lo na forma: Salário de 1234 reais e 65 centavos.
Observações:
a)	Orientar o usuário na forma como deve ser informado o percentual
(por exemplo, 10 para 10% ou 0.1 para 10%), ou seja, como que o programa espera que o valor seja informado.
 Isso é importante para definir a fórmula.
b)	Cálculos de percentual podem ser realizados por meio de regras de três.

*/
int main (void)
{

    float Sala,P1,P2,S1,S2,Final;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe o Seu Salario: ");
        scanf("%f"&Sala);
        printf("Informe o percentual de aumento: ");
        scanf("%f"&P1);
        printf("Informe o percentual de descontos: ");
        scanf("%f"&P2);

        system("cls");

        S1 = (Sala*P1)/100;
        S2 = (Sala*P2)/100;

        Final =

        printf("_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
