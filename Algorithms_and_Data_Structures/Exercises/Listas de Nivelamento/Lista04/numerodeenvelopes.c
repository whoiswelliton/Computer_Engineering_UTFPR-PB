#include <stdio.h>

int main(){

	int i;
	int n, k;
	int x;

	scanf (" %d %d", &n, &k);
	int vet[k+1];
	memset (vet, 0, sizeof(int)*(k+1));

	for (i=0; i<n; i++){

		scanf (" %d", &x);
		vet[x]++;

	}

	int menor = 1;
	for (i=2; i<k+1; i++)
		if (vet[i] < vet[menor])
			menor=i;

	printf ("%d\n",vet[menor]);
	return 0;

}