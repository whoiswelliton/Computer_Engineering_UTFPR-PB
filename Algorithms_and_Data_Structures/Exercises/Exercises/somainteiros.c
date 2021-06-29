#include <stdio.h>
#include <stdlib.h>

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
	return p;
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

	novo-> conteudo = conteudo;
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
	novo->prox = NULL;
	novo->conteudo = conteudo;
	
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
	celula *p =l->inicio;
	
	while(p->prox != NULL)
	{ 
		printf(" => %d", p->conteudo);
		p = p->prox;
		      		
	}
	printf(" => %d", p->conteudo);
}

void soma_inteiro_listas(listaDENC *A, listaDENC *B, listaDENC *C)
{
	int soma,sobra,dif, i, maior;
	soma = sobra = dif = i = 0;

	celula *x = A->inicio;
	celula *y = B->inicio;
	
	if(A->cont > B->cont)
	{
		dif = A->cont - B->cont;
		for(i=0; i < dif; i++)
		{
			insere_fim(B,0);
		}
		
	}
	else if(B->cont > A->cont)
	{
		dif = B->cont - A->cont;
		for(i=0; i < dif; i++)
		{
			insere_fim(A,0);
		}
	}

	
	printf("\nlistas atualizadas\n");
	imprimelista(A);
	printf("\n");
	imprimelista(B);
	printf("\n");
	
	while(maior > 0)
	{ 
		soma = soma + x->conteudo + y->conteudo;
		
		printf("\nsoma atual: %d\n",soma);

		if(soma > 0 && soma < 10 && sobra == 0)
		{
			insere_inicio(C, soma);
			soma = 0;
		}
		else
		{
			sobra = soma - 10; 
			printf("\nsobra: %d",sobra);
			insere_inicio(C, sobra);
			soma = 1;
			sobra = 0;
		}
		maior--;
		remove_inicio(A);
		remove_inicio(B);
		/*
		printf("\nlistas:\n");
		imprimelista(A);
		printf("\n");
		imprimelista(B);
		printf("\n");*/


	}
	if(soma == 1)
	{
		insere_inicio(C, soma);
		soma = 0;
	}
}




int main(void)
{
	int i,j;
	int num1=0;
	int num2=0;
	i=j=0;

	listaDENC *A = inicializa();
	listaDENC *B = inicializa();
	listaDENC *C = inicializa();
	
	char *stringA = (char *)malloc(512000 * sizeof(char));
   	char *stringB = (char *)malloc(512000 * sizeof(char));
   	scanf("%s %s", stringA, stringB);

	while(stringA[i] != '\0')
	{
		int num1 = (int)(stringA[i] - '0');
		//printf("\n%d\n",num1);
		insere_inicio(A,num1);   
		i++;           
	}
	while(stringB[j] != '\0')
	{
		int num2 = (int)(stringB[j] - '0');
		//printf("\n%d\n",num2);
		insere_inicio(B,num2);   
		j++;           
	}
	
	soma_inteiro_listas(A,B,C);

	imprimelista(C);
	printf("\n");
	return(0);
}
