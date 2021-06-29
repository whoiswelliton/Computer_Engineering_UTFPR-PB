#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define TAM 1021

//TABELA HASH COM TRATAMENTO DE COLISÕES POR ENCADEAMENTO SEPARADO

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

int HASH(int conteudo)
{
	return(conteudo % TAM);
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
		return (0);
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

void imprimelista (listaDENC *l)  		
{
	celula *p;

	for(p = l->inicio;p != NULL;p = p->prox)
	{ 
      		printf("%d ", p->conteudo);
	}
}

void imprime_lista (listaDENC *l)  		
{
	celula *p =l->inicio;
	
	while(p->prox != NULL)
	{ 
		printf("%d ", p->conteudo);
		p = p->prox;
		      		
	}
	printf("%d ", p->conteudo);
}

void UNIAO (listaDENC **tabA, listaDENC **tabB, listaDENC **tabC)
{
	int i,j;
	int flagrepetida=0;
	i=j=0;
	for (i = 0; i < TAM; i++)
	{
		if(tabA[i]->inicio != NULL)
		{
			for(j = 0;j < TAM; j++)
			{
				if(tabC[j]->inicio != NULL)
				{		
					if(tabC[j]->inicio->conteudo == tabA[i]->inicio->conteudo)
					{
						flagrepetida = 1;
					}
				}
	       		 }

			if(flagrepetida == 0)
			{
					insere_fim(tabC[HASH(tabA[i]->inicio->conteudo)],tabA[i]->inicio->conteudo);	
	       	 	}
			else
			{
				flagrepetida = 0;
			} 
		}
	}

	i=j=0;

	for (i = 0; i < TAM; i++)
	{
		if(tabB[i]->inicio != NULL)
		{
			for(j = 0;j < TAM; j++)
			{
				if(tabC[j]->inicio != NULL)
				{		
					if(tabC[j]->inicio->conteudo == tabB[i]->inicio->conteudo)
					{
						flagrepetida = 1;
					}
				}
	       		 }

			if(flagrepetida == 0)
			{
					insere_fim(tabC[HASH(tabB[i]->inicio->conteudo)],tabB[i]->inicio->conteudo);
				
	
	       	 	}
			else
			{
				flagrepetida = 0;
			} 
		}
	}
	
}

int main(void)
{
	int i,j,A,B,C;
	int conteudo;
	int flagrepetida=0;
	i=j=A=B=C=0;
  
    scanf("%d",&A);  
	listaDENC** tabA = (listaDENC**)malloc(TAM*sizeof(listaDENC*));

    for (i = 0; i < TAM; i++) 
    {
        tabA[i] = inicializa();  
    }
   	for(i = 0;i < A; i++)               
    { 
        scanf("%d",&conteudo); 
	insere_fim(tabA[HASH(conteudo)],conteudo);
   }

	i=j=0;
   	scanf("%d",&B); 
   	listaDENC** tabB = (listaDENC**)malloc(TAM*sizeof(listaDENC*));

    for (i = 0; i < TAM; i++) 
    {
        tabB[i] = inicializa();  
    }
    for(i = 0;i < B; i++)               
    { 
        scanf("%d",&conteudo);
	for(j = 0;j < TAM; j++)
        	{
			if(tabB[j]->inicio != NULL)
			{		
				if(tabB[j]->inicio->conteudo == conteudo)
				{
					flagrepetida = 1;
				}
			}
       		 }

        	if(flagrepetida == 0)
        	{
        		insere_fim(tabB[HASH(conteudo)],conteudo);
       	 	}
		else
		{
			flagrepetida = 0;
		}   

   }
 
 	C = A+B;
 	listaDENC** tabC = (listaDENC**) malloc(TAM*sizeof(listaDENC*));

    for (i = 0; i < TAM; i++) 
    {
        tabC[i] = inicializa();  
    }

    UNIAO(tabA, tabB, tabC);


    for(i = 0;i < TAM; i++)
    { 
        if(tabC[i]->inicio != NULL)
		{
            imprime_lista(tabC[i]);
		}
  	} 

	return(0);
}

