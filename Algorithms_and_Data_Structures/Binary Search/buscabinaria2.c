int busca_bin (int n, int* vet, int elem) 
{
/* no início consideramos todo o vetor */
int ini = 0
;
int fim = n-1;
/* enquanto a parte restante for maior que zero */
while (ini <= fim) 
{
int meio = (ini + fim) / 2;
if (elem < vet[meio])
‏
fim = meio –1;  
/* ajusta posição final */
else if (elem > vet[meio])
‏
ini = meio + 1;  
/* ajusta posição inicial */
else
return meio;     
/* elemento encontrado */
}
/* não encontrou: restou parte de tamanho zero */
return -1
}
