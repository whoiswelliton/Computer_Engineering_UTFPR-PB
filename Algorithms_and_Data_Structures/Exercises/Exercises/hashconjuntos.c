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

int main(void)
{
	int i,j, N;
	int conteudo;
	int flagrepetida=0;
	i=j=0;
  
    	scanf("%d",&N);  

	listaDENC** tab = (listaDENC**)malloc(TAM*sizeof(listaDENC*));

   	for (i = 0; i < TAM; i++) 
   	{
   	     tab[i] = inicializa();  
    	}


   	for(i = 0;i < N; i++)               
    	{ 
    		scanf("%d",&conteudo); 

        	for(j = 0;j < TAM; j++)
        	{
			if(tab[j]->inicio != NULL)
			{		
				if(tab[j]->inicio->conteudo == conteudo)
				{
					flagrepetida = 1;
				}
			}
       		 }

        	if(flagrepetida == 0)
        	{
        		insere_fim(tab[HASH(conteudo)],conteudo);
       	 	}
		else
		{
			flagrepetida = 0;
		}
      

  	 }


    for(i = 0;i < TAM; i++)
    { 
        if(tab[i]->inicio != NULL)
	{
            imprime_lista(tab[i]);
	}
    } 

	return(0);
}

