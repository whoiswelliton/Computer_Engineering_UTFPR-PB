#include <stdio.h>

int F91 (int N)
{
	if(N <= 100)
	{
		return F91 (F91 (N + 11));

	}
	else if(N >= 101)
	{
		return(N - 10);
	}

}

int main()
{
	int N;

	while((scanf("%d",&N)) && (N!=0))
	{
		printf("f91(%d) = %d\n",N, F91(N));
	}

	return 0;
}

