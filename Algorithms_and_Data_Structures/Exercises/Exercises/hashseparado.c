
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//Tabelas hash: encadeamento separado (inserção) 


typedef struct aluno{
	long matricula;
	char nome[100];            
	struct aluno*prox;
	struct aluno*ant;
}aluno;

typedef struct listaDENC{				
	aluno*inicio;
	int cont;
}listaDENC;

listaDENC *inicializa()
{
	listaDENC* l = (listaDENC*) malloc(sizeof(listaDENC));

	l->inicio = NULL;
	l->cont = 0;
	
	return l;
}

aluno *cria(long matricula, char *nome)			
{
	aluno *p = (aluno*)malloc(sizeof(aluno));
	p->matricula = matricula;
	strcpy(p->nome,nome);
	p->prox = NULL;
	p->ant = NULL;
	return p;
}

int pilha_vazia(listaDENC *p)
{
	if(p == NULL || p->inicio == NULL)
	{
		//Pilha vazia
		return 1;
	}
	return 0;
}

int HASH(long matricula, int  n)
{
	return(matricula % n);
}

int insere_inicio(listaDENC *l, long matricula, char *nome)
{
	if(l == NULL)
	{
		return 0;
	}

	aluno *novo = cria(matricula, nome);

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
int insere_fim(listaDENC *l, long matricula, char *nome)	
{
	if(l->inicio==NULL)
	{
		return(insere_inicio(l,matricula,nome));
	}
	
	aluno *novo = cria(matricula, nome);

	if(novo==NULL)
	{
		return (0); //falso
	}
	//novo->prox = NULL;
	//novo->conteudo = conteudo;
	
	aluno *ultimo = l->inicio;

	while(ultimo->prox !=NULL)
	{
		ultimo = ultimo->prox;
		
	}

	ultimo->prox=novo;
	l->cont++;
	return 1; 
}

void imprime_lista (listaDENC *l)  		
{
	aluno *p =l->inicio;
	
	while(p->prox != NULL)
	{ 
		printf("%ld, ", p->matricula);
		p = p->prox;
		      		
	}
	printf("%ld\n", p->matricula);
}

int main(void)
{
	int capacidade;
	int n, i=0;
	long matricula;
	char nome[100];
  
    	scanf("%d",&capacidade);  
	scanf("%d",&n); 
	

	listaDENC** tab = (listaDENC**)malloc(capacidade*sizeof(listaDENC*));


   	for (i = 0; i < capacidade; i++) 
    	{
     	   	tab[i] = inicializa();   
    	}
 	i=0;  
	for (i = 0; i < n; i++) 
    	{
		scanf("%ld %s",&matricula, nome);
   		insere_fim(tab[HASH(matricula,capacidade)],matricula,nome);   
	}  
	i=0;
	for(i=0;i<capacidade;i++)
	{
		printf("%d:",i);
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

