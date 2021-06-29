#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int n,i,num,soma=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%d",&num);
    soma = soma + num;
    }
    printf("%d\n",soma);
    return(0);
}
