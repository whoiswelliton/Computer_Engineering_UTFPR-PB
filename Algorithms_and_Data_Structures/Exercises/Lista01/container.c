#include <stdio.h>

int main (void)
{
	int A,B,C,X,Y,Z;
	int qtd,l,h,b;

	scanf("%d %d %d",&A,&B,&C);
	scanf("%d %d %d",&X,&Y,&Z);
	
	l=(int)X/A;
	h=(int)Y/B;
	b=(int)Z/C;
	
	qtd = l*h*b;
	
	printf("%d\n",qtd);
	
	return 0;	
}
