#include <stdio.h>
int main(void)
{
    int h,m,s,resto,total;
    while((scanf("%d:%d:%d",&h,&m,&s))!=EOF)
    {
        resto = s + (m*60) + (h*3600);
        resto = 86400 - resto;
        printf("%d\n",resto);
    }
    return(0);
}
