#include<stdio.h>
#include<stdlib.h>

int main (void)
{
    int num, sec, min, h;

    printf("informe um valor: ");
    scanf("%d",&num);

    h=num/3600;
    min=num%3600/60;
    sec=num%60;

    printf("esse valor representa: ");
    printf("%02d : %02d : %02d",h,min,sec);

}
