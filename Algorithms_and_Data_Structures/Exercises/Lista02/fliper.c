#include <stdio.h>

int main (void)
{
	int P1,P2;

	scanf("%d %d",&P1,&P2);
	
	if(P1==1 && P2==1)
	{
		printf("A\n");
	}
	else if(P1==1 && P2==0)
	{
		printf("B\n");
	}
	else
	{
		printf("C\n");
	}
	
	return 0;
}
