/*	

Projeto de Compiladores
Parte 1 - Analisador Léxico

WELLITON LEAL 

ESTRUTURA DE DADOS UTILIZADA:
LISTA DUPLAMENTE ENCADEADA ALOCADA DINAMICAMENTE

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct celula{
	char *token;
	int linha;
	int erro;                  
	struct celula *prox;
	struct celula *ant;
}celula;

typedef struct listaDENC{				
	celula *inicio;
	celula *fim;
	int cont;
}listaDENC;

listaDENC *inicializa()
{
	listaDENC* l = (listaDENC*) malloc(sizeof(listaDENC));

	l->inicio = NULL;
	l->fim = NULL;
	l->cont = 0;
	
	return l;
}

celula *cria(char *entrada, int linha, int erro)			
{
	celula *no = (celula*)malloc(sizeof(celula));

	no->token = entrada;
	no->linha = linha;
	no->erro = erro;
	no->prox = NULL;
	no->ant = NULL;

	return no;
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

int insere_inicio(listaDENC *l, char* entrada, int linha, int erro)
{
	if(l == NULL)
	{
		return 0;
	}

	celula *novo = cria(entrada, linha, erro);

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

int insere_fim(listaDENC *l, char *entrada, int linha, int erro)	
{
	if(l->inicio == NULL)
	{
		return(insere_inicio(l, entrada, linha, erro));
	}
	
	celula *novo = cria(entrada, linha, erro);

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

	printf("\nLISTA:\n");

	for(p = l->inicio;p != NULL;p = p->prox)
	{ 
      		printf(" < %s, %d >", p->token, p->linha);

      		if(p->erro == 1)
      		{
      			printf("    ***Erro do Tipo 1 - Numero Inválido - na linha: %d",p->linha);
      		}
      		else if(p->erro == 2)
      		{
      			printf("    ***Erro do Tipo 2 - Identificador Invalido - na linha: %d",p->linha);
      		}

      		printf("\n");

	}

	printf("\n");
}

void apaga_lista (listaDENC *l)
{
	int i=0;

	celula *ant = l->inicio;
	celula *atual = l->inicio;

	while (atual != NULL)
	{
		ant = atual;
		atual = atual->prox;
		free(ant);
	}

	l->inicio = NULL;
	l->fim = NULL;
	l->cont = 0;
}

int analisador_lexico (listaDENC *l)
{

	char *entrada2;
	int tamtotal = 0;

	char entrada [100];
	int linha = 0;
	int i=0,j=0;
	int FLAG1=0,FLAG2=0;
	int erro;

	FILE *file;
    file = fopen("input7.txt", "r");

    if(file == NULL)
    {
        printf("\n [ERRO] - Nao e possivel abrir seu arquivo de entrada.\n");
        exit(0);
    }
    else
    {
    	printf("\nENTRADA:\n\n");

    	while(fscanf(file, "%ms",&entrada2) != EOF)
	    {
	    	printf(" %s", entrada2);
	    	tamtotal = strlen(entrada2);
	    }

	    printf("\n\nLINHA :\n");
    	while(fgets (entrada, sizeof(entrada), file) != NULL)
	    {
	    	char *palavra; 

	    	printf("\n  %s", entrada);

	    	int tam = strlen(entrada);
	    	printf("\nTamanho: %d\n", tam);
	    	
	    	while (entrada[i] != '\0')
	    	{

	    		//TRATANDO COMENTÁRIOS 

	    		if (entrada[i] == '/' && entrada[i+1] == '*')
				{
					i=i+2;
					FLAG1 = 1;
					printf("\n <<< Comentario Aberto ");
				}
				else if(entrada[i] == '*' && entrada[i+1] == '/')
	    		{
	    			i=i+2;
					FLAG1 = 0;
					printf("\n >>> Comentario Fechado ");
	    		}

				if(FLAG1 == 0 && entrada[i] != '\n')
	    		{
	    			printf("\n1");

	    			if(entrada[i] == ' ')
	    			{
	    				printf("\n5");
	    			}

	    		}
	    		
	    		i++;
	    	}

	    	//CONTAGEM DE LINHAS

	    	if(entrada[i] == '\n')
	    	{
	    		linha++;
	    	}
	    }

	    if(FLAG1 == 1) 
	    {
	    	printf("\n [ERRO] - Sua entrada possui um comentario que foi aberto e nunca fechado");
	   	}
		
    }
    

    printf("\n  *** A Entrada tem %d Linhas", linha);
    
	printf("\n");
	fclose(file);
	return(0);
}

int main(void)
{
	int TAM=10;
	
	listaDENC* l = (listaDENC*)malloc(TAM*sizeof(listaDENC));

	l = inicializa();

	analisador_lexico(l);

	imprimelista(l);

	apaga_lista(l);
	
	return(0);
}