#include <stdio.h>
#include <stdlib.h>

int main(){

	int n;
	int i, aux;
	int maisrepete;

	int vet[101];
	memset (vet, 0, sizeof(int)*101);

	scanf (" %d", &n);
	for (i=0; i<n; i++){
		scanf (" %d", &aux);
		vet[aux]++;
	}

	maisrepete=0;
	for (i=1; i<101; i++){

		if ((vet[i]>vet[maisrepete]) || (vet[i]==vet[maisrepete] && i>maisrepete))
			maisrepete = i;
	}

	printf ("%d\n", maisrepete);
	return 0;



}