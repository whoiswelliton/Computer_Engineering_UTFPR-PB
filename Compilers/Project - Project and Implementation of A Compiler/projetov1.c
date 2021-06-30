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
	bool erro;                  
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

celula *cria(char *palavra, int linha, bool erro)			
{
	celula *no = (celula*)malloc(sizeof(celula));

	no->token = palavra;
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

int insere_inicio(listaDENC *l, char* palavra, int linha, bool erro)
{
	if(l == NULL)
	{
		return 0;
	}

	celula *novo = cria(palavra, linha, erro);

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

int insere_fim(listaDENC *l, char *palavra, int linha, bool erro)	
{
	if(l->inicio == NULL)
	{
		return(insere_inicio(l, palavra, linha, erro));
	}
	
	celula *novo = cria(palavra, linha, erro);

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
      			printf(" ***Erro Lexico Econtrado na linha: %d",p->linha);
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

	char *palavra;
	int linha = 1;
	int i=0,j=0;
	int FLAG1=0,FLAG2=0;
	bool erro;

	FILE *Entrada;
    Entrada = fopen("input5.txt", "r");

    if(Entrada == NULL)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo de entrada.\n");
        exit(0);
    }
    else
    {
    	printf("\nENTRADA:\n");

    	//while(fgets (palavra,1000, file) != NULL)
    	while(fscanf(Entrada, "%ms",&palavra) != EOF)
	    {

	    	printf(" %s", palavra);

	    	//TRATANDO COMENTARIOS COM UMA FLAG DE CONTROLE
			
			if (!strcmp(palavra, "/*"))
			{
				FLAG2 = 1;
			}

	    	else if(FLAG2 == 0)
			{
				//TRATANDO TOKENS E TERMINAIS

				printf("\nr  - %d\n",strcmp("inicio", "inicio"));
		    	if (!strcmp(palavra, "inicio"))
		    	{
					insere_fim(l,"START", linha, 0);
					linha++;
				}
				else if (!strcmp(palavra, "fim"))
		    	{
					insere_fim(l,"END", linha, 0);
					linha++;
				}
				else if (!strcmp(palavra, "int"))
		    	{
					insere_fim(l,"INT", linha, 0);
				}
				else if (!strcmp(palavra, "leia"))
		    	{
					insere_fim(l,"READ", linha, 0);
				}
				else if (!strcmp(palavra, "escreva"))
		    	{
					insere_fim(l,"WRITE", linha, 0);
				}
				else if (!strcmp(palavra, ":"))
		    	{
					insere_fim(l,"TWODOTS", linha, 0);
				}
				else if (!strcmp(palavra, ":="))
		    	{
					insere_fim(l,"ATRIB", linha, 0);
				}
				else if (!strcmp(palavra, ","))
		    	{
					insere_fim(l,"COMMA", linha, 0);
				}
				else if (!strcmp(palavra, ";"))
		    	{
					insere_fim(l,"DOTCOMMA", linha, 0);
					linha++;
				}
				else if (!strcmp(palavra, "("))
		    	{
					insere_fim(l,"LBRACKET", linha, 0);
				}
				else if (!strcmp(palavra, ")"))
		    	{
					insere_fim(l,"RBRACKET", linha, 0);
				}
				else if (!strcmp(palavra, "+"))
		    	{
					insere_fim(l,"ADDITION", linha, 0);
				}
				else if (!strcmp(palavra, "-"))
		    	{
					insere_fim(l,"SUBTRACTION", linha, 0);
				}
				else if (!strcmp(palavra, "*"))
		    	{
					insere_fim(l,"MULTIPLICATION", linha, 0);
				}

				//TRATANDO NÚMEROS

				else if (palavra[0] >= '0' && palavra[0] <= '9')
				{
					i = FLAG1 = 0;

					while(i < strlen(palavra))
					{
						if (palavra[i] < '0' || palavra[i] > '9')
						{
							FLAG1 = 1;
						}

						i++;
					}
					if (FLAG1 == 1) 
					{
						insere_fim(l, "NUMBER", linha, 1);
					}
					else if (FLAG1 == 0) 
					{
						insere_fim(l, "NUMBER", linha, 0);
					}

				}
				
				//TRATANDO IDENTIFICADORES

		    	else if (palavra[0] >= 'a' && palavra[0] <= 'z' || palavra[0] >= 'A' && palavra[0] <= 'Z')
		    	{
		    		i = FLAG1 = 0;

					while(i < strlen(palavra))
					{
						if (!(palavra[i] >= '0' && palavra[i] <= '9' || palavra[i] >= 'a' && palavra[i] <= 'z' || palavra[i] >= 'A' && palavra[i] <= 'Z'))
						{
							FLAG1 = 1;
						}

						i++;
					}
					if(FLAG1 == 1)
					{
						insere_fim(l, "ID", linha, 1);
					}
					else if(FLAG1 == 0)
					{
						insere_fim(l, "ID", linha, 0);
					}

				}
			}
			else if (!strcmp(palavra, "*/"))
			{
				FLAG2 = 0;
			}
	    }
    }
    
	printf("\n");
	fclose(Entrada);
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