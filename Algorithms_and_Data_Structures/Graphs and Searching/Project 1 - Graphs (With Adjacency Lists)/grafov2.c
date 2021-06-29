//TRABALHO 1 - Algoritmos e Estrutura de Dados II

//ALUNO - Welliton Leal

//GRAFO POR MEIO DE LISTAS DE ADJACÊNCIA ALOCADAS DINÂMICAMENTE

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
	int conteudo;           
	struct celula *prox;
	struct celula *baixo;
}celula;

typedef struct lista{
	int contV; 
	int contA;              
	struct celula *inicioV;
	struct celula *inicioA;
	
}lista;

celula *nova_celula(int conteudo)			
{
	celula *c = malloc(sizeof(celula));

	c->conteudo = conteudo;
	c->prox = NULL;
	c->baixo = NULL;
	return c;
}

lista *nova_lista()
{
	lista *l = (lista*) malloc(sizeof(lista));
	
	l->inicioV = NULL;
	l->inicioA = NULL;
	l->contV = 0;
	l->contA = 0;

	return l;
}

int verifica_vertice(lista *v, int conteudo)
{
	celula *p = malloc(sizeof(celula));

	for(p = v->inicioV; p != NULL ; p = p->baixo)
	{ 
	      	if(p->conteudo == conteudo)
			{
				return 1;
			}
	}
	return 0;
}

int verifica_aresta(lista *a, int conteudo)
{
	celula *p = malloc(sizeof(celula));

	for(p = a->inicioA; p != NULL ; p = p->prox)
	{ 
	      	if(p->conteudo == conteudo)
			{
				return 1;
			}
	}
	return 0;
}


int insere_vertice(lista *l, int conteudo)	
{
	if(l->inicioV == NULL)
	{
		if(l == NULL)
		{
			return 0;
		}

		celula *novo = nova_celula(conteudo);

		if(novo == NULL)
		{
			return 0;
		}

		novo->conteudo = conteudo;
		novo->baixo = l->inicioV;
		novo->prox = NULL;
		l->inicioV = novo;
		l->contV++;

		printf("\n + Vertice %d Inserido\n",novo->conteudo);

		return 1;
	}
	else
	{
		if(verifica_vertice(l, conteudo) == 0)
		{
			celula *novo = nova_celula(conteudo);

			if(novo == NULL)
			{
				return (0);
			}

			novo->prox = NULL;
			novo->baixo = NULL;
			novo->conteudo = conteudo;
			
			celula *ultimo = l->inicioV;

			while(ultimo->baixo != NULL)
			{
				ultimo = ultimo->baixo;
			}

			ultimo->baixo = novo;
			l->contV++;

			printf(" + Vertice %d Inserido\n",novo->conteudo);

			return 1; 
			
		}
		else
		{
			printf(" ***Entrada Invalida, O vertice %d ja Existe!\n",conteudo);
			return 0;
		}	
	}
}

int insere_aresta1(lista *l, int conteudo1, int conteudo2)
{
	celula *p;

	for(p = l->inicioV; p != NULL ; p = p->baixo)
	{ 
		if(p->conteudo == conteudo1)
		{
				
			if(l->inicioA == NULL)
			{
				if(l == NULL)
				{
					return 0;
				}

				celula *novo = nova_celula(conteudo2);

				if(novo == NULL)
				{
					return 0;
				}

				novo->conteudo = conteudo2;
				novo->baixo = NULL;
				novo->prox = l->inicioA;
				l->inicioA = novo;
				l->contA++;

				printf(" + Aresta %d Inserido\n",novo->conteudo);

				return 1;
			}
			else
			{
				if(verifica_aresta(l, conteudo2) == 0)
				{
					celula *novo = nova_celula(conteudo2);

					if(novo == NULL)
					{
						return (0);
					}

					novo->prox = NULL;
					novo->baixo = NULL;
					novo->conteudo = conteudo2;
					
					celula *ultimo = l->inicioA;

					while(ultimo->prox != NULL)
					{
						ultimo = ultimo->prox;
					}

					ultimo->prox = novo;
					l->contA++;

					printf(" + Aresta %d Inserida\n",novo->conteudo);

					return 1; 
					
				}
				else
				{
					printf(" ***Entrada Invalida, A Aresta %d ja Existe!\n",conteudo2);
					return 0;
				}	
			}
		}
	}
}

int insere_aresta2(lista *v, int conteudo1, int conteudo2)
{
	if(v->inicioV == NULL) 
	{
		printf("\nNao existe nenhum vertice no grafo, impossivel adicionar aresta. \n");
	}
	else
	{
		if(verifica_vertice(v, conteudo1) == 1 && verifica_vertice(v, conteudo2) == 1)
		{
			printf("\nOK - Os Dois vertices existem...\n");

			if(conteudo1 == conteudo2)	
			{
				insere_aresta1(v, conteudo1, conteudo1);
			}
			else
			{
				insere_aresta1(v, conteudo1, conteudo2);
				insere_aresta1(v, conteudo2, conteudo1);
			}	
		}
		else
		{
			printf("\nEntrada Invalida, Algum dos Vertices inseridos nao existe!\n");
			return 0;
		}
	}	
}

void imprime_lista (lista *l)  		
{
	celula *p;
	celula *q;

	for(p = l->inicioV; p != NULL;p = p->baixo)
	{ 
		printf("\n V[%d] | ", p->conteudo);
		for(q = l->inicioA; q != NULL; q = q->prox)
		{ 
      		printf("=> %d ",q->conteudo);
      	}
	}
	printf("\n\n");
}

int main(void)
{

	lista *V = (lista*) malloc(sizeof(lista));

	V = nova_lista();

	insere_vertice(V, 1);
	insere_vertice(V, 2);
	insere_vertice(V, 3);
	insere_vertice(V, 4);

	insere_aresta2(V, 1, 2);
	insere_aresta2(V, 3, 4);
	//insere_aresta2(V, 2, 2);

	imprime_lista(V);

	return 0;
}