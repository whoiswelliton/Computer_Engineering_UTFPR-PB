#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//PILHA => LIFO/Last-In-First-Out

typedef struct celula{
	char conteudo;             
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
		printf("Pilha vazia\n");
		return 1;
	}
	return 0;
}

int empilha(pilhaD *p, char conteudo)
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


int desempilha(pilhaD *p)
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
      		printf("%c", novo->conteudo);
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
	pilhaD p;
	int i=0;
	double res;
	
	inicializa(&p);
	
    	char* expressao = (char *)malloc(512000 * sizeof(char));
   	scanf("%s", expressao);

	while(expressao[i] != '\0')
	{
		
		if(isdigit(expressao[i]) == true)
		{
			
			double num = (double)(expressao[i]-'0');
			empilha(&p,num);
		}
		else if(expressao[i] == '+')
		{
			printf("encontrou soma\n");

			double aux1 = p->conteudo;
			desempilha(&p);

			double aux2 = ;
			desempilha(&p);

			res = aux1 + aux2;
			empilha(&p, res);
			printf("empilhou a resposta\n");
					
		}
		/*else if(expressao[i] == '-')
		{
		}
		else if(expressao[i] == '*')
		{
		}
		else if(expressao[i] == '/')
		{
			
		}	
		else if(expressao[i] == '^')
		{
				
		}*/
		
    		i++;
	}

	printf("%.6f",res);
	printf("\n");
	imprime_pilha (&p);

	apaga_pilha (&p);
	return 0;
}


