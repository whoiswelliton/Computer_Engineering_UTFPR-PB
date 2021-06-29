#include <stdio.h>

int main (void)
{
	int n,x;
	int soma=0;
	int i=0;

	scanf("%d",&n);
	while (i<n)
	{
		scanf("%d",&x);
		soma = soma + x;
		i++;
	}
	printf("%d\n",soma);

	return 0;
}
