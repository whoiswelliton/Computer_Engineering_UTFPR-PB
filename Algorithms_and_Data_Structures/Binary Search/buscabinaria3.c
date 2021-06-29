Funcionario* busca (int n, Funcionario** v, char* nome) {
/* no início consideramos todo o vetor */
int ini = 0;
int fim = n-1;
/* enquanto a parte restante for maior que zero */
while (ini <= fim) {
int meio = (ini + fim) / 2;

switch (strcmp(nome, v[meio]->nome)) 
{
	case -1:fim = meio –1;  
	/* ajusta posição final */
	break;
	case 1:ini = meio + 1;  
	/* ajusta posição inicial */
	break;
	case 0:return v[meio];     
	/* elemento encontrado */
}
}
/* não encontrou: restou parte de tamanho zero */
return NULL;
