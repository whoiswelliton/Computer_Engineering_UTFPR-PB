#include <stdio.h>

int main (void)
{
	int A,i=1986;
	
	scanf("%d",&A);

	while(i<=A+76)
	{	
		if(i>A)
		{
			printf("%d\n",i);
		}
		i=i+76;
	}
	return 0;	
}
