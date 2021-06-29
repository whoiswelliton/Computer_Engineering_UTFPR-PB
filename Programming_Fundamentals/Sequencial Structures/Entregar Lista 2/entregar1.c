#include<stdio.h>
#include<stdlib.h>

int main (void)
{
    int  est, tra, dor, total;
    float percent;

    printf("informe a quantidade de horas gasta dormindo: ");
    scanf("%d",&dor);
    printf("informe a quantidade de horas gasta estudando: ");
    scanf("%d",&est);
    printf("informe a quantidade de horas gasta trabalhando: ");
    scanf("%d",&tra);

    total=est+tra+dor;
    percent=dor/total*100.0;

    printf("vc gasta %.2f%% das horas semanais dormindo\n",dor);

    percent=est/total*100.0;

    printf("vc gasta %.2f%% das horas semanais estudando\n",est);

    percent=tra/total*100.0;

    printf("vc gasta %.2f%% das horas semanais trabalhando\n",tra);
}
