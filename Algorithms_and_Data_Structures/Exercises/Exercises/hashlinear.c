#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct aluno
{
    	long matricula;
    	char nome[100];
    	struct aluno* prox;
    	struct aluno* ant;

}aluno;
typedef struct lista
{
	aluno* inicio;
    	aluno* fim;
    	int cont;
}lista;

lista *inicializa()
{
	lista* l = (lista*) malloc(sizeof(lista));

	l->inicio = NULL;
	l->fim = NULL;
	l->cont = 0;
	
	return l;
}

aluno *cria(long matricula, char *nome)			
{
	aluno *p = (aluno*)malloc(sizeof(aluno));
	p->matricula = matricula;
	strcpy(p->nome,nome);
	p->prox = NULL;
	p->ant = NULL;
	return p;
}

int HASH(long conteudo, int tam)
{
	return conteudo % tam;
}

int REhash(int hash_conteudo, int tam)
{
	return (hash_conteudo + 1) % tam;
}
int insere_inicio(lista *l, long matricula, char *nome)
{
	if(l == NULL)
	{
		return 0;
	}

	aluno *novo = cria(matricula, nome);

	novo->prox = l->inicio;
	novo->ant = NULL;
	l->inicio = novo;
	if(novo->prox != NULL)
	{
		novo->prox->ant = novo;
	}

	l->cont++;
	return 1;
}

void inserir_tabela(lista **tabela_hash, int capacidade, long matricula, char *nome)
{	
	int r = HASH(matricula, capacidade);
	int qtd = 0;

	aluno* aux = cria(matricula, nome);

	while (tabela_hash[r]->inicio->matricula != -1  && qtd < capacidade)
	{
		r = REhash(r,capacidade);
		qtd++;
	}
	if (qtd < capacidade) 
	{
		tabela_hash[r]->inicio->matricula = aux->matricula;
		strcpy(tabela_hash[r]->inicio->nome, aux->nome);
	}
}
void imprime_hash(lista** tabela_hash, int capacidade)
{
	for (int i = 0; i < capacidade; i++)
	{
		if(tabela_hash[i]->inicio->matricula == -1)
		{
			printf("%d\t%ld\n", i, tabela_hash[i]->inicio->matricula);
		}
		else
		{
			printf("%d\t%ld\t%s\n", i, tabela_hash[i]->inicio->matricula, tabela_hash[i]->inicio->nome);
		}	
	}
}

int main(void)
{
	int capacidade;
	int n, i=0;
	long matricula;
    	char nome[100];

	scanf("%d",&capacidade);  
	scanf("%d",&n); 

	lista** tabela_hash = (lista**) malloc(capacidade*sizeof(lista*));
	
	for (i = 0; i < capacidade; i++)
	{
		tabela_hash[i] = inicializa();
		insere_inicio(tabela_hash[i], -1, nome);
	}
	for(i = 0;i < n; i++)               
    	{ 
    		scanf("%ld %s",&matricula, nome);
	
       		inserir_tabela(tabela_hash, capacidade, matricula, nome); 
    	}

	imprime_hash(tabela_hash,capacidade);
	return 0;
}
