#include <stdio.h>
#include <stdlib.h>

int main(){

	int a; //numero de aeroportos
	int v; //numero de voos
	int i;
	int x,y;
	int teste=1;

	while (scanf (" %d %d", &a, &v) && a!=0 && v!=0){
	
		/*vet contém a frequência de aeroportos, assim, o aeroporto
		"i" tem uma frequência de vet[i]*/
		int vet[a+1];
		memset(vet, 0, sizeof(int)*(a+1));

		for (i=0; i<v; i++){
			scanf (" %d %d", &x, &y);
			vet[x]++; vet[y]++;
		}

		/*procura o aeroporto com mais tráfego*/
		int maiorfrequencia = 1;
		for (i=2; i< a+1; i++){
			if (vet[i] > vet[maiorfrequencia])
				maiorfrequencia = i;
		}

		/*imprime a lista de aeroportos com maior frequencia*/
		printf ("Teste %d\n", teste++);
		for (i=1; i<a+1; i++)
			if (vet[i] == vet[maiorfrequencia])
				printf ("%d ", i);
		printf ("\n\n");
	}

	return 0;


}