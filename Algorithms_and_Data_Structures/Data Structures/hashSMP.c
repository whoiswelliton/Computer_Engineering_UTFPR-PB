#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//#define tam 10 - Posso definir meu tamanho da hash ou fazer uma leitura na main

//TABELA HASH COM TRATAMENDO DE COLISÕES POR TESTE LINEAR

typedef struct celula
{
    	int conteudo;
    	//char nome[100]; //long matricula; .....
    	struct celula* prox;
    	struct celula* ant;

}celula;

typedef struct lista
{
	celula* inicio;
    	celula* fim;
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

celula *cria(int conteudo)			
{
	celula *p = (celula*)malloc(sizeof(celula));
	p->conteudo = conteudo;
	//strcpy(p->nome,nome);
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

int insere_inicio(lista *l, int conteudo)
{
	if(l == NULL)
	{
		return 0;
	}

	celula *novo = cria(conteudo);

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

void inserir_tabela(lista **tabela_hash, int capacidade, int conteudo)
{	
	int r = HASH(conteudo, capacidade);
	int qtd = 0;

	celula *aux = cria(conteudo);

	while (tabela_hash[r]->inicio->conteudo != -1  && qtd < capacidade)
	{
		r = REhash(r,capacidade);
		qtd++;
	}
	if (qtd < capacidade) 
	{
		tabela_hash[r]->inicio->conteudo = aux->conteudo;
		//strcpy(tabela_hash[r]->inicio->nome, aux->nome);
	}
}

void imprime_hash(lista** tabela_hash, int capacidade)
{
	int i=0;

	for (int i = 0; i < capacidade; i++)
	{
		printf("\nTab[%d]: %d\n", i, tabela_hash[i]->inicio->conteudo);
	}

	printf("\n");
}

int main(void)
{
	int tam, conteudo, i=0;

	printf("\nEntre com a quantidade de linhas da tabela = ");   
    	scanf("%d",&tam);  

	lista** tabela_hash = (lista**) malloc(tam*sizeof(lista*));

	for (int i = 0; i < tam; i++)
	{
		tabela_hash[i] = inicializa();
		insere_inicio(tabela_hash[i], -1);
	}

	for(i = 0;i < tam; i++)               
    	{ 
    		printf("\nEntre com o valor da chave = "); 
        	scanf("%d",&conteudo); 

        	inserir_tabela(tabela_hash, tam, conteudo); 
    	}

    	imprime_hash(tabela_hash,tam);

	
	return 0;
}
