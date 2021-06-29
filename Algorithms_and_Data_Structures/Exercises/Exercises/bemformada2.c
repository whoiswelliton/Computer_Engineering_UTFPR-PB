#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//BEM FORMADA

typedef struct celula{
	char info;             
	struct celula*prox;
}celula;
typedef struct pilhaD{				
	celula*topo;
	int cont;
}pilhaD;

pilhaD *inicializa()
{
	pilhaD* p = (pilhaD*) malloc(sizeof(pilhaD));
	p->topo = NULL;
	p->cont = 0;
	return p;
}

celula *cria(char info)			
{
	celula *p = malloc(sizeof(celula));
	p->info = info;
	p->prox = NULL;
	return p;
}

int pilha_vazia(pilhaD *p)
{
	if(p == NULL || p->topo == NULL)
	{
		return 1;
	}
	return 0;
}

int empilha(pilhaD *p, char info)
{
	if(p == NULL)
	{
		return 0;
	}
	celula *novo = cria(info);
	if(novo == NULL)
	{
		return 0;
	}

	novo->info =info;
	novo->prox = p->topo;
	p->topo = novo;
	p->cont++;
	return 1;
}


int desempilha(pilhaD *p)
{
	if(p == NULL || p->topo == NULL)
	{
		printf("Nao ha elementos na pilha\n");       
		return 0;
	}

	char ret = p->topo->info;
	
	celula *rmv = p->topo;
	p->topo = p->topo->prox;
	free(rmv);
	p->cont--;
	return(ret);
}

celula *busca_topo (pilhaD *p)
{
	celula *novo = p->topo;
	printf("\n Topo: %d\n\n",novo->info);
	return novo;
}

void imprime_pilha (pilhaD *p)  		
{
	celula *novo;
	for(novo = p->topo;novo != NULL;novo = novo->prox)
	{ 
      		printf("%d\n", novo->info);
	}
}

void apaga_pilha (pilhaD *p)
{
	int i=0;

	celula *ant = p->topo;
	celula *atual = p->topo;

	while (atual != NULL)
	{
		ant = atual;
		atual = atual->prox;
		free(ant);
	}
	p->topo = NULL;
	p->cont = 0;
}

int bemformada (pilhaD *A, char *s)
{
	int i=0;

	while(s[i] != '\0')
	{
		//celula *novo = cria(s[i]);

		if(s[i] == '(' || s[i] == '[' || s[i] == '{')
		{	
			empilha(A, s[i]);
		}
		else if(s[i] == ')')
		{
			if(desempilha(A) != '(')
			{
				break;
			}
		}
		else if(s[i] == ']')
		{
			if(desempilha(A) != '[')
			{
				break;
			}
		}
		else if(s[i] == '}')
		{
			if(desempilha(A) != '{')
			{
				break;
			}
		}
		i++;
	}
	if(pilha_vazia(A) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}

int main(void)
{
	int i=0;
	int t;
	int FLAG;

   	scanf("%d",&t);
   	for(int i = 0; i < t; i++)
	{
		char *s = (char *)malloc(10240 * sizeof(char));
		scanf("%s",s);
		
		pilhaD *A = (pilhaD*)malloc(10240*sizeof(pilhaD));
		A = inicializa();
	
		FLAG = bemformada(A, s);

		if(FLAG == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");	
		}
   	}
	
	//apaga_pilha (A);

	return 0;
}


