#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PILHA (LIFO/Last-In-First-Out) ALOCADA DINAMICAMENTE

typedef struct celula{
	int conteudo;             
	struct celula*prox;
}celula;
typedef struct pilha{				
	celula*inicio;
	int cont;
}pilha;

pilha *inicializa()
{
	pilha* p = (pilha*) malloc(sizeof(pilha));

	p->inicio = NULL;
	p->cont = 0;
	
	return p;
}
celula *cria(int conteudo)			
{
	celula *p = malloc(sizeof(celula));
	p->conteudo = conteudo;
	p->prox = NULL;
	return p;
}

int pilha_vazia(pilha *p)
{
	if(p == NULL || p->inicio == NULL)
	{
		return 1;
	}
	return 0;
}

int empilha(pilha *p, int conteudo)
{
	if(p == NULL)
	{
		return 0;
	}
	celula *novo = cria(conteudo);
	if(novo == NULL)
	{
		return 0;
	}

	novo->prox = p->inicio;
	p->inicio = novo;
	p->cont++;
	return 1;
}


int desempilha(pilha *p)
{
	if(p == NULL || p->inicio == NULL)
	{
		printf("Nao ha elementos na pilha\n");       
		return 0;
	}

	int ret = p->inicio->conteudo;
	
	celula *rmv = p->inicio;
	p->inicio = p->inicio->prox;
	free(rmv);
	p->cont--;
	return(ret);
}

celula *busca_topo (pilha *p)
{
	celula *novo = p->inicio;
	printf("\n Topo: %d\n\n",novo->conteudo);
	return novo;
}

void imprime_pilha (pilha *p)  		
{
	celula *novo;
	for(novo = p->inicio;novo != NULL;novo = novo->prox)
	{ 
      		printf("%d\n", novo->conteudo);
	}
}


void apaga_pilha (pilha *p)
{
	int i=0;

	celula *ant = p->inicio;
	celula *atual = p->inicio;

	while (atual != NULL)
	{
		ant = atual;
		atual = atual->prox;
		free(ant);
	}
	p->inicio = NULL;
	p->cont = 0;
}

void maiorelemento(pilha *p)
{
	long maior=0;
	celula *novo;
	for(novo = p->inicio;novo != NULL;novo = novo->prox)
	{ 
		if(novo->conteudo > maior)
		{
			maior = novo->conteudo;
		}
	}

	printf("%ld",maior);
}

int main(void)
{
	int i=0;
	long num1,num2,num3;
	
	scanf("%ld",&num1);

	pilha* p = (pilha*)malloc(num1*sizeof(pilha));

	p = inicializa();
	
	for(i=0; i < num1; i++)
	{
		scanf("%ld", &num2);

		if(num2 == 1)
		{
			scanf("%ld", &num3);
			empilha(p,num3);
		}
		else if(num2 == 2)
		{
			if(pilha_vazia(p) == 0)
			{
				desempilha(p);
			}
				
		}
		else if(num2 == 3)
		{
			if(pilha_vazia(p) == 0)
			{
				maiorelemento(p);
			}
		}
	}

	apaga_pilha (p);

	return 0;
}


