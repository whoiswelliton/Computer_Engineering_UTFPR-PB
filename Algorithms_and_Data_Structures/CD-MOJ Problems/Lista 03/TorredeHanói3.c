#include<stdio.h>
#include<stdlib.h>
#include <math.h>
void TorreHanoi(int ND,int i)
{
    int Hanoi;
    Hanoi=(int)pow(2,ND)-1;
    printf("\nTeste %d\n%d\n",i,Hanoi);
}
int main()
{
    int ND,i=1;

    while(scanf("%d",&ND) != 0)
    {
        if(ND <= 30 && ND >= 0)
        {
            i++;
            TorreHanoi(ND,i);
        }
    }

    return 0;
}
