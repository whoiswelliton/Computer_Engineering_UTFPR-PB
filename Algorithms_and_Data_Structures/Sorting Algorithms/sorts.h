
void bubbleSort(int vet[], int tam){
	int i = 0, j, aux;
	do {
		for(j = 0; j < tam - 1; j++){
			if(vet[j] < vet[j + 1]){
				aux = vet[j + 1];
				vet[j + 1] = vet[j];
				vet[j] = aux;
				i = 1;
			}
		}	tam--;
	}	while(i && tam > 1 );
}

void quickSort(int vet[], int inicio, int fim){
	int i = inicio, j = fim, aux, med = vet[(int)((inicio + fim)/2)];
	while(i < j){
		while(vet[i] < med)
			i++;
		while(vet[j] > med)
			j--;
		if(i <= j){
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++; j--;
		}
	}
	if(j > inicio) quickSort(vet, inicio, j);
	if(i < fim) quickSort(vet, i, fim);
}

void mergeSort(int vet[], int tam){
	if(tam < 2) return;
	int i, j, k,med = (int)(tam/2), l[med], r[tam - med];
	for(i = 0; i < med -1; i++)
		l[i] = vet[i];
	for(i = med; i < tam -1; i++)
		r[i - med] = vet[i];
	mergeSort(l, med);
	mergeSort(r, tam - med);

	for(i = 0, j = 0, k = 0; i < med && j < tam - med; k++){
		if(l[i] < r[j])	vet[k] = l[i++];
		else	vet[k] = r[j++];
	}
	while(i < med)
		vet[k++] = l[i++];
	while(j < tam - med)
		vet[k++] = r[j++];
}

void insertionSort(int vet[], int tam){
	int i, j, aux;
	for(i = 1; i < tam; i++){
		aux = vet[i];
		j = i - 1;
		while(j >= 0 && aux < vet[j])
			vet[j+1] = vet[j--];
		vet[j+1] = aux;
	}
}

