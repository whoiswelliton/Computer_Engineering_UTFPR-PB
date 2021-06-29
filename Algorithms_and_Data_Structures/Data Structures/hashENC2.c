#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//TABELA HASH COM TRATAMENTO DE COLISÕES POR ENCADEAMENTO SEPARADO

typedef struct celula{
	int conteudo;
	//char nome[100];                 
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

int HASH(int conteudo, int n)
{
	return(conteudo % n);
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
	//novo->prox = NULL;
	//novo->conteudo = conteudo;
	
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
      		printf("=> %d ", p->conteudo);
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
	int conteudo;
	int N;

	printf("\nEntre com a quantidade de linhas da tabela = ");   
    	scanf("%d",&N);  

	listaDENC** tab = (listaDENC**)malloc(N*sizeof(listaDENC*));

    	for (i = 0; i < N; i++) 
    	{
        	tab[i] = inicializa();  
    	}

   	 for(i = 0;i < N; i++)               
    	{ 
    		printf("\nEntre com o valor da chave = "); 
        	scanf("%d",&conteudo);  

        	insere_fim(tab[HASH(conteudo,N)],conteudo);        
   	}

    	i=0;

    	for(i = 0;i < N; i++)
    	{
     		printf("\n Tab[%d]: ",i);  
        	if(tab[i]->cont > 0)
		{
            		imprime_lista(tab[i]);
		}
       		else
		{
         		printf("\n");
		}

  	} 

	return(0);
}

