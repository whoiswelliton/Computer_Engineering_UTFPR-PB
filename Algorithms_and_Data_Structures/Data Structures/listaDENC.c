#include <stdio.h>
#include <stdlib.h>

//LISTA DUPLAMENTE ENCADEADA ALOCADA DINAMICAMENTE

typedef struct celula{
	int conteudo;                  
	struct celula*prox;
	struct celula*ant;
}celula;

typedef struct listaDENC{				
	celula*inicio;
	int cont;
}listaDENC;

listaDENC *inicializa()
{
	listaDENC* l = (listaDENC*) malloc(sizeof(listaDENC));

	l->inicio = NULL;
	l->cont = 0;
	
	return l;
}

celula *cria(int conteudo)			
{
	celula *p = malloc(sizeof(celula));
	p->conteudo = conteudo;
	p->prox = NULL;
	p->ant = NULL;
	return p;
}

int lista_vazia(listaDENC *l)
{
	if(l == NULL)
	{
		return 1;
	}
	if(l->inicio == NULL)
	{
		return 1;
	}
	return 0;
}

int insere_inicio(listaDENC *l, int conteudo)
{
	if(l == NULL)
	{
		return 0;
	}
	celula *novo = cria(conteudo);
	if(novo == NULL)
	{
		return 0;
	}

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

int insere_fim(listaDENC *l, int conteudo)	
{
	if(l->inicio==NULL)
	{
		return(insere_inicio(l,conteudo));
	}
	
	celula *novo = cria(conteudo);

	if(novo==NULL)
	{
		return (0); //falso
	}
	
	celula *ultimo = l->inicio;

	while(ultimo->prox !=NULL)
	{
		ultimo = ultimo->prox;
		
	}

	ultimo->prox=novo;
	l->cont++;
	return 1; 
}

int remove_inicio(listaDENC *l)
{
	if(l == NULL || l->inicio == NULL)
	{
		return 0;
	}
	
	celula *novo = l->inicio;
	l->inicio = novo->prox;
	if(novo->prox != NULL)
	{
		novo->prox->ant = NULL;
	}

	free(novo);
	l->cont--;
	return 1;
}

int remove_fim (listaDENC *l)
{
	if(l == NULL || l->inicio == NULL)
	{
		return 0;
	}

	celula *ultimo = l->inicio;

	while(ultimo->prox != NULL)
	{
		ultimo = ultimo->prox;
	}

	if(ultimo->ant == NULL)
	{
		printf("\n1\n");
		l->inicio = ultimo->prox;
	}
	else
	{	
		printf("\n3\n");
		ultimo->ant->prox = NULL;
	}
	printf("\n4\n");

	free(ultimo);
	l->cont--;
	return 1;

}

void imprimelista (listaDENC *l)  		
{
	celula *p;
	for(p = l->inicio;p != NULL;p = p->prox)
	{ 
      		printf("=> %d\n", p->conteudo);
	}
}
void imprime_lista (listaDENC *l)  		
{
	celula *p =l->inicio;
	
	while(p->prox != NULL)
	{ 
		printf("=> %d ", p->conteudo);
		p = p->prox;
		      		
	}
	printf("=> %d\n", p->conteudo);
}


int main(void)
{
	int i=0;
	int TAM;
	
	scanf("%d",&TAM);

	listaDENC* l = (listaDENC*)malloc(TAM*sizeof(listaDENC));

	l = inicializa();
	
	for (i = 0; i < TAM; ++i)
	{
		insere_inicio(l, rand()%10);              
	}

	insere_fim(l,3);

	printf("\n");

	imprimelista (l);

	printf("\n-> APOS REMOVER:\n\n");


	remove_inicio(l);
	//remove_fim(l);

	imprimelista (l);

	
	
	return(0);
}
