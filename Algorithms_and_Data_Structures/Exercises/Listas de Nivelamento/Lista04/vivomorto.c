#include <stdio.h>

int main(){

	int p, r;
	int i,k;
	int x;
	int a;
	int n,j;
	int teste=1;

	while (scanf (" %d %d", &p, &r) && p!=0 && r!=0){

		int lista[p]; //vetor de participantes
		
		/*lendo a fila*/
		for (i=0; i<p; i++){
			scanf (" %d", &x);
			lista[i]=x;
		}

		/*lendo as rodadas*/
		for (i=0; i<r;i++){
			scanf (" %d %d", &n, &j); //n = numero de participantes da rodada
									 //j = ordem dada pelo chefe
			for (k=0; k<p; k++){ //lendo a ação dos participantes
					if (lista[k] != -1){
						scanf (" %d", &a);
						if (a != j){
							lista[k]=-1;
						}
					}
			}
		}

		for (k=0; k<p; k++)
			if (lista[k]!= -1){
				printf ("Teste %d\n",teste++);
				printf ("%d\n\n",lista[k]);
			}
	}

	return 0;

}