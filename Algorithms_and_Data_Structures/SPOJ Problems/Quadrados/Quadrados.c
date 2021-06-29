#include <stdio.h>

int Quadrados (int N)
{
	int R;
	R = N * N;
    return(R);
}

int main()
{
	int N;
	while((scanf("%d",&N)) && (N!=0) && (N<=1000))
	{
            Quadrados(N);
            printf("%d\n",Quadrados(N));
	}
	return 0;
}
