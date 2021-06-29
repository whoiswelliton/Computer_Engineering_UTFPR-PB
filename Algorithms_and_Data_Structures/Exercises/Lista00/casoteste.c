#include <stdio.h>

int main (void)
{
	int n,i=0;
	int Ri;
	int A=0,B=0;

	while(scanf("%d",&n) && n!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&Ri);
			if(Ri==0)
			{
				A++;
			}
			else if(Ri==1)
			{
				B++;
			}
		}
		printf("Alice ganhou %d e Beto ganhou %d\n",A,B);
		A=0;B=0;
	}
	return 0;
}
