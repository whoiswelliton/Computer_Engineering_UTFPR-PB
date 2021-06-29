#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PILHA (LIFO/Last-In-First-Out) ALOCADA DINAMICAMENTE

typedef struct celula{
	int conteudo;
	struct celula*prox;
}celula;
typedef struct pilhaD{
	celula*inicio;
	int cont;
}pilhaD;

void inicializa(pilhaD *p)
{
	p->inicio = NULL;
	p->cont = 0;
}

celula *cria(int conteudo)
{
	celula *p = malloc(sizeof(celula));
	p->conteudo = conteudo;
	p->prox = NULL;
	return p;
}

int pilha_vazia(pilhaD *p)
{
	if(p == NULL || p->inicio == NULL)
	{
		return 1;
	}
	return 0;
}

int empilha(pilhaD *p, int conteudo)
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

	novo-> conteudo = conteudo;
	novo->prox = p->inicio;
	p->inicio = novo;
	p->cont++;
	return 1;
}


char desempilha(pilhaD *p)
{
	if(p == NULL || p->inicio == NULL)
	{
		return 0;
	}

	int ret = p->inicio->conteudo;

	celula *rmv = p->inicio;
	p->inicio = p->inicio->prox;
	free(rmv);
	p->cont--;
	return(ret);
}

celula *busca_topo (pilhaD *p)
{
	celula *novo = p->inicio;
	printf("\n Topo: %d\n\n",novo->conteudo);
	return novo;
}

void imprime_pilha (pilhaD *p)
{
	celula *novo;
	for(novo = p->inicio;novo != NULL;novo = novo->prox)
	{
      		printf("%c\n", novo->conteudo);
	}
}


void apaga_pilha (pilhaD *p)
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

int main(void)
{
    	char s[100];
	pilhaD p;
	int i=0;

	inicializa(&p);
	scanf("%s",&s);

	while(s[i]!='C')
    	{
		empilha(&p,s[i]);
		i++;
    	}

    	empilha(&p, s[i]);

   	while(s[i]!='\0')
        {
       
          	if(desempilha(&p) == s[i])
            	{
               		 i++;
            	}
            	else
            	{
		        printf("NÃO");
		        return -1;
            	}
    	}

	if(pilha_vazia(&p) == 1)
	{
	    printf("SIM");

	}
	else
	{
	    printf("NÃO");
	}

	apaga_pilha(&p);

    return 0;
}
