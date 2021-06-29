#include <stdio.h>

int main (void)
{
	int A,B,C;

	scanf("%d %d %d",&A,&B,&C);
	
	if(B>A && C<A || C>A && B<A)
	{
		printf("%d\n",A);
	}
	else if(A>B && C<B || C>B && A<B)
	{
		printf("%d\n",B);
	}
	else if(A>C && B<C || B>C && A<C)
	{
		printf("%d\n",C);
	}
	
	return 0;
}
