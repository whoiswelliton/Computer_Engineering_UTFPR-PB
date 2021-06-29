#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
    float alt, larg, numj, nump, altj, largj, altp, largp, area, areaj, areap, gasto, total, areat=0;

    printf("informe a altura da parede: ");
    scanf("%f",&alt);
    printf("informe a largura da parede: ");
    scanf("%f",&larg);
    printf("informe o numero de janela: ");
    scanf("%f",&numj);
    printf("informe o numero de portas: ");
    scanf("%f",&nump);
    printf("informe a altura da janela: ");
    scanf("%f",&altj);
    printf("informe o largura da janela: ");
    scanf("%f",&largj);
    printf("informe a altura da porta: ");
    scanf("%f",&altp);
    printf("informe a largura da porta: ");
    scanf("%f",&largp);
    printf("informe o gasto de tinta por metro quadrado: ");
    scanf("%f",&gasto);

    area=alt*larg;
    areaj=altj*largj;
    areap=altp*largp;
    areat=area-(areaj*numj)-(areap*nump);
    total=areat/gasto;
    area=ceil(total);

    printf("seram necessarias %.0f latas de tinta",area);

}
