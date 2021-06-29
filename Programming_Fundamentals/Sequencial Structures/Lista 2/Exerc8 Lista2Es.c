#include <stdio.h>
#include <stdlib.h>
/* Um viajante viajará de carro entre duas cidades e ao término deseja saber:
_ Quantas vezes foi necessário abastecer;
_ Quantos litros foram consumidos para percorrer a distancia indicada;
_ Quantos litros restaram no tanque apos a chegada ao destino.
Faca um programa em C que leia a distância entre as duas cidades, a capacidade do tanque
 e o consumo médio do veiculo, calcule e mostre as informações solicitadas.
*/

int main (void)
{
    int QAbast;
    float Qlitros, LitrosT, Dist, CapaT, Consumo;

    printf("Informe a distancia entre as cidades: ");
    scanf("%f",&Dist);
    printf("Informe a capacidade do tanque: ");
    scanf("%f",&CapaT);
    printf("Informe o consumo médio do veiculo: ");
    scanf("%f",&Consumo);

    QAbast = ((Dist/Consumo)/CapaT)+0.999999;
    Qlitros = (Dist/Consumo);
    LitrosT = (QAbast*CapaT-Qlitros);

    printf("A quantidade de abastecimentos vai ser: %d\n",QAbast);
    printf("A quantidades de litros consumidos e de: %.2f\n",Qlitros);
    printf("A quantidade de litros que sobraram no tanque e: %.2f\n",LitrosT);

    system("pause");
}
