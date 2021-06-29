#include <stdio.h>

int main (void)
{
	int N;

	scanf("%d",&N);
	
	if(N==0)
	{
		printf("E\n");
	}
	else if(N>0 && N<=35)
	{
		printf("D\n");
	}
	else if(N>35 && N <=60)
	{
		printf("C\n");
	}
	else if(N>60 && N <=85)
	{
		printf("B\n");
	}
	else if(N>=86 && N <=100)
	{
		printf("A\n");
	}
	return 0;
}
