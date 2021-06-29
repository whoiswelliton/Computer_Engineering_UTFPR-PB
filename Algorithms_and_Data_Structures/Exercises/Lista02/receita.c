#include <stdio.h>

int main (void)
{
	int A,B,C,i=0;
	scanf("%d %d %d",&A,&B,&C);
	while(A >= 2 && B>=3 && C>=5)
	{
		i++;
		
		A=A-2;
		B=B-3;
		C=C-5;
	}
	printf("%d\n",i);
	return 0;
}
