#include <stdio.h>
#include <string.h>
int main(void)
{
    int qtdsim=0,qtdtriagem=0,qtdentradas=0;
    char R1[3];
    while((scanf("%s",&R1))!=EOF)
    {
        qtdentradas++;
        if(strcmp(R1,"sim") == 0)
        {
            qtdsim++;
        }
        if(qtdentradas==10)
        {
            qtdentradas=0;
        }
        if(qtdsim == 2)
        {
            qtdtriagem++;
            qtdsim=0;
        }
    }
    printf("%d\n",qtdtriagem);
    return 0;
}
