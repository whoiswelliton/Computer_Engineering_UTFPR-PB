#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FILA (FIFO = First-In-First-Out)) ALOCADA DINAMICAMENTE

typedef struct celula{
	int conteudo;             
	struct celula*prox;
}celula;
typedef struct fila{				
	celula*inicio;
	int cont;
}fila;

fila *inicializa()
{
	fila* f = (fila*) malloc(sizeof(fila));

	f->inicio = NULL;
	f->cont = 0;
	
	return f;
}

celula *cria(int conteudo)			
{
	celula *f = malloc(sizeof(celula));
	f->conteudo = conteudo;
	f->prox = NULL;
	return f;
}

int fila_vazia(fila *f)
{
	if(f == NULL || f->inicio == NULL)
	{
		printf("fila vazia\n");
		return 1;
	}
	return 0;
}

int enfila(fila *f, int conteudo)
{
	if(f == NULL)
	{
		return 0;
	}
	celula *novo = cria(conteudo);
	if(novo == NULL)
	{
		return 0;
	}
	novo->prox = f->inicio;
	f->inicio = novo;
	f->cont++;
	return 1;
}


int desenfila (fila *f)
{
	if(f == NULL || f->inicio == NULL)
	{
		printf("Nao ha elementos na fila\n"); 
		return 0;
	}
	celula *ant = f->inicio;
	celula *novo = f->inicio;
	while(novo->prox != NULL)
	{
		ant = novo;
		novo = novo->prox;
	}
	if(novo == f->inicio)
	{
		f->inicio = novo->prox;
	}
	else
	{
		ant->prox = novo->prox;
	}

	free(novo);
	f->cont--;
	return 0;

}

void imprime_fila(fila *f)  		
{
	celula *novo;
	for(novo = f->inicio;novo != NULL;novo = novo->prox)
	{ 
      		printf("%d\n", novo->conteudo);
	}
}

void imprime_fila2 (fila *f)  		
{
	celula *p =f->inicio;
	
	while(p->prox != NULL)
	{ 
		printf("=> %d ", p->conteudo);
		p = p->prox;
		      		
	}
	printf("=> %d\n", p->conteudo);
}


void apaga_fila (fila *f)
{
	int i=0;

	celula *ant = f->inicio;
	celula *atual = f->inicio;

	while (atual != NULL)
	{
		ant = atual;
		atual = atual->prox;
		free(ant);
	}
	f->inicio = NULL;
	f->cont = 0;
}

int main(void)
{
	int i=0;
	int TAM;
	
	scanf("%d",&TAM);

	fila* f = (fila*)malloc(TAM*sizeof(fila));

	f = inicializa();
	
	for (i = 0; i < TAM; i++)
	{
		enfila(f, rand()%10 );              
	}

	imprime_fila (f);

	printf("-> APOS REMOVER:\n");

	desenfila(f);
	desenfila(f);

	imprime_fila (f);

	apaga_fila (f);

	return 0;
}
