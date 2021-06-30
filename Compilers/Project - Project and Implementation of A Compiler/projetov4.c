/*	

DISCIPLINA: Compiladores
Aluno: WELLITON LEAL 

PŔOJETO:
Analisador Léxico & Analisador Sintático

ESTRUTURAS DE DADOS UTILIZADA:
Lista Para Tokens - Lista Duplamente Encadeada Alocada Dinamicamente
Pilha Para Operações - Pilha Alocada Dinamicamete

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct celula{
	char *token;
	char *palavra;
	int linha;
	int erro;                  
	struct celula *prox;
	struct celula *ant;
}celula;

typedef struct celula2{
	char *palavra;             
	struct celula2*prox;
}celula2;

typedef struct listaDENC{				
	celula *inicio;
	celula *fim;
	int cont;
}listaDENC;

typedef struct pilha{				
	celula2*inicio;
	int cont;
}pilha;


listaDENC *inicializalista()
{
	listaDENC* l = (listaDENC*) malloc(sizeof(listaDENC));

	l->inicio = NULL;
	l->fim = NULL;
	l->cont = 0;
	
	return l;
}

pilha *inicializapilha()
{
	pilha* p = (pilha*) malloc(sizeof(pilha));

	p->inicio = NULL;
	p->cont = 0;
	
	return p;
}

celula *cria(char *entrada, char *palavra, int linha, int erro)			
{
	celula *no = (celula*)malloc(sizeof(celula));

	no->token = entrada;
	no->palavra = palavra;
	no->linha = linha;
	no->erro = erro;
	no->prox = NULL;
	no->ant = NULL;

	return no;
}

celula2 *cria2(char *conteudo)			
{
	celula2 *no = (celula2*)malloc(sizeof(celula2));

	no->palavra = conteudo;
	no->prox = NULL;

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

int pilha_vazia(pilha *p)
{
	if(p == NULL || p->inicio == NULL)
	{
		printf("\n  *** Pilha Vazia ***\n");
		return 1;
	}

	return 0;
}

int empilha(pilha *p, char *conteudo)
{
	if(p == NULL)
	{
		return 0;
	}

	celula2 *novo = cria2(conteudo);

	if(novo == NULL)
	{
		return 0;
	}

	novo->prox = p->inicio;
	p->inicio = novo;
	p->cont++;

	return 1;
}

int desempilha(pilha *p)
{
	if(p == NULL || p->inicio == NULL)
	{
		printf("Nao ha elementos na pilha\n");       
		return 0;
	}

	int ret = *p->inicio->palavra;
	
	celula2 *rmv = p->inicio;
	p->inicio = p->inicio->prox;
	p->cont--;

	free(rmv);
	return(ret);
}


int insere_inicio(listaDENC *l, char *entrada, char *palavra, int linha, int erro)
{
	if(l == NULL)
	{
		return 0;
	}

	celula *novo = cria(entrada, palavra, linha, erro);

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

int insere_fim(listaDENC *l, char *entrada, char *palavra, int linha, int erro)	
{
	if(l->inicio == NULL)
	{
		return(insere_inicio(l, entrada, palavra, linha, erro));
	}
	
	celula *novo = cria(entrada, palavra, linha, erro);

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

	printf("\n----------------------[ TOKENS: ]-------------------------\n\n");

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

void imprime_pilha (pilha *p)  		
{
	celula2 *novo;

	printf("\n----------------------[ PILHA: ]-------------------------\n\n");

	for(novo = p->inicio; novo != NULL;novo = novo->prox)
	{ 
      		printf("%s\n", novo->palavra);
	}
}

celula2 *busca_topo (pilha *p)
{
	celula2 *novo = p->inicio;

	printf("\n  => Topo: %s\n\n",novo->palavra);

	return (novo);
}

void apaga_pilha (pilha *p)
{
	int i=0;

	celula2 *ant = p->inicio;
	celula2 *atual = p->inicio;

	while (atual != NULL)
	{
		ant = atual;
		atual = atual->prox;
		free(ant);
	}

	p->inicio = NULL;
	p->cont = 0;
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

	char *entrada;
	int linha = 1;
	int i=0,j=0;
	int FLAG1=0,FLAG2=0;
	int erro;

	FILE *file;
    file = fopen("input0.txt", "r");

    if(file == NULL)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo de entrada.\n");
        exit(0);
    }
    else
    {
    	printf("\n---------------------[ ENTRADA: ]------------------------\n\n");

    	//while(fgets (entrada,100, file) != NULL)
    	while(fscanf(file, "%ms",&entrada) != EOF)
	    {

	    	printf(" %s", entrada);

	    	if(strcmp(entrada, "inicio") == 0 || strcmp(entrada, ";") == 0 || strcmp(entrada, "fim") == 0 || strcmp(entrada, "*/") == 0)
	    	{
	    		printf("\n");
	    	}

	    	//TRATANDO COMENTARIOS COM UMA FLAG DE CONTROLE
			
			if (!strcmp(entrada, "/*"))
			{
				FLAG2 = 1;
			}

	    	else if(FLAG2 == 0)
			{
				//TRATANDO TERMINAIS

		    	if (!strcmp(entrada, "inicio"))
		    	{
					insere_fim(l,"INICIO", entrada, linha, 0);
					linha++;
				}
				else if (!strcmp(entrada, "fim"))
		    	{
					insere_fim(l,"FIM", entrada, linha, 0);
					linha++;
				}
				else if (!strcmp(entrada, "int"))
		    	{
					insere_fim(l,"INT", entrada, linha, 0);
				}
				else if (!strcmp(entrada, "leia"))
		    	{
					insere_fim(l,"LEIA", entrada, linha, 0);
				}
				else if (!strcmp(entrada, "escreva"))
		    	{
					insere_fim(l,"ESCREVA", entrada, linha, 0);
				}
				else if (!strcmp(entrada, ":"))
		    	{
					insere_fim(l,"DOIS_PNT", entrada, linha, 0);
				}
				else if (!strcmp(entrada, ":="))
		    	{
					insere_fim(l,"ATRIB", entrada, linha, 0);
				}
				else if (!strcmp(entrada, ","))
		    	{
					insere_fim(l,"VIRG", entrada, linha, 0);
				}
				else if (!strcmp(entrada, ";"))
		    	{
					insere_fim(l,"PNT_VIRG", entrada, linha, 0);
					linha++;
				}
				else if (!strcmp(entrada, "("))
		    	{
					insere_fim(l,"ABRE_P", entrada, linha, 0);
				}
				else if (!strcmp(entrada, ")"))
		    	{
					insere_fim(l,"FECHA_P", entrada, linha, 0);
				}
				else if (!strcmp(entrada, "+"))
		    	{
					insere_fim(l,"ADICAO", entrada, linha, 0);
				}
				else if (!strcmp(entrada, "-"))
		    	{
					insere_fim(l,"SUBTRACAO", entrada, linha, 0);
				}
				else if (!strcmp(entrada, "*"))
		    	{
					insere_fim(l,"MULTIPLICACAO", entrada, linha, 0);
				}

				//TRATANDO NÚMEROS

				else if (entrada[0] >= '0' && entrada[0] <= '9')
				{
					i = FLAG1 = 0;

					while(i < strlen(entrada))
					{
						if (entrada[i] < '0' || entrada[i] > '9')
						{
							FLAG1 = 1;
						}

						i++;
					}
					if (FLAG1 == 1) 
					{
						insere_fim(l, "NUMERO", entrada, linha, 1);
					}
					else if (FLAG1 == 0) 
					{
						insere_fim(l, "NUMERO", entrada, linha, 0);
					}

				}
				
				//TRATANDO IDENTIFICADORES

		    	else if (entrada[0] >= 'a' && entrada[0] <= 'z' || entrada[0] >= 'A' && entrada[0] <= 'Z')
		    	{
		    		i = FLAG1 = 0;

					while(i < strlen(entrada))
					{
						if (!(entrada[i] >= '0' && entrada[i] <= '9' || entrada[i] >= 'a' && entrada[i] <= 'z' || entrada[i] >= 'A' && entrada[i] <= 'Z'))
						{
							FLAG1 = 1;
						}

						i++;
					}
					if(FLAG1 == 1)
					{
						insere_fim(l, "ID", entrada, linha, 2);
					}
					else if(FLAG1 == 0)
					{
						insere_fim(l, "ID", entrada, linha, 0);
					}

				}
			}
			else if (!strcmp(entrada, "*/"))
			{
				FLAG2 = 0;
			}
	    }
    }

	printf("\n");
	fclose(file);
	return(0);
}

void analisador_sintatico (listaDENC *Tokens, pilha *Pilha)
{
	if(Tokens->cont > 0)
	{
		insere_fim(Tokens, "CIFRAO", "$",0, 0);

		empilha(Pilha, "$");
		empilha(Pilha, "PROGRAMA");

		celula *T;

		printf("\n---------------------[ OPERACOES: ]----------------------\n\n");

		for(T = Tokens->inicio; T != NULL; T = T->prox)
		{ 
	
			printf("\n ################# LOOP ##################\n");
			printf("\n XXX PILHA = %s - TOKEN = %s XXX\n",Pilha->inicio->palavra, T->token);

			//TRATANDO A PRODUÇÃO PROGRAMA - OK
			if(strcmp(Pilha->inicio->palavra, "(") == 0 && strcmp(T->token,"ABRE_P") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
			    desempilha(Pilha);
			    T = T->prox;
			}
			if(strcmp(T->token,"FECHA_P") == 0 && ((strcmp(T->prox->token,"MULTIPLICACAO") == 0 || strcmp(T->prox->token,"ADICAO") == 0) || strcmp(T->prox->token,"SUBTRACAO") == 0))
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
			    desempilha(Pilha);

				empilha(Pilha,"EXP");
				printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
				empilha(Pilha,"OP");	
				printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
			}		
			if(strcmp(Pilha->inicio->palavra, ")") == 0 && strcmp(T->token,"FECHA_P") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
			    desempilha(Pilha);
			    //T = T->prox;
			}
			if(strcmp(Pilha->inicio->palavra, "id") == 0 && strcmp(T->token,"ID") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
				desempilha(Pilha);
				//T = T->prox;
			}

			if(strcmp(Pilha->inicio->palavra, "PROGRAMA") == 0 && strcmp(T->token,"INICIO") == 0)
			{
				//printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
				desempilha(Pilha);

				empilha(Pilha, "fim");
				empilha(Pilha, ";");
				empilha(Pilha, "COMANDOS");
				empilha(Pilha, ";");
				empilha(Pilha, "DECL_SEQUENCIA");
				empilha(Pilha, "inicio");

				if(strcmp(Pilha->inicio->palavra, "inicio") == 0 && strcmp(T->token, "INICIO") == 0)
				{
					//printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
	                desempilha(Pilha);
	                T = T->prox;  
	            }
			}
			
            //TRATANDO A PRODUÇÃO DECL_SEQUENCIA - OK

			if(strcmp(Pilha->inicio->palavra, "DECL_SEQUENCIA") == 0 && strcmp(T->token, "INT") == 0)
			{
				//printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
				desempilha(Pilha);

				empilha(Pilha, "DECL");
				//printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
				empilha(Pilha, ":");
				//printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
				empilha(Pilha, "int");
				//printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);

				if(strcmp(Pilha->inicio->palavra, "int") == 0 && strcmp(T->token,"INT") == 0)
				{
					//printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
	                desempilha(Pilha);
	                T = T->prox;
	            }
	            if(strcmp(Pilha->inicio->palavra, ":") == 0 && strcmp(T->token,"DOIS_PNT") == 0)
				{
					//printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
	                desempilha(Pilha);
	                T = T->prox;
	            }
			}
			
            //TRATANDO PRODUÇÃO DECL - OK

			if(strcmp(Pilha->inicio->palavra, "DECL") == 0 && strcmp(T->token,"ID") == 0)
			{
				//printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
				desempilha(Pilha);

				if(strcmp(T->prox->token,"VIRG") == 0)
				{
					empilha(Pilha, "DECL");
					//printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, ",");
					//printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, "id");
					//printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
				}   
				if(strcmp(T->prox->token,"PNT_VIRG") == 0)
				{
					empilha(Pilha, "id");
					//printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
				}
				if(strcmp(Pilha->inicio->palavra, "id") == 0 && strcmp(T->token,"ID") == 0)
				{
					//printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
		            desempilha(Pilha);
		            T = T->prox;
		        }
		        if(strcmp(Pilha->inicio->palavra, ",") == 0 && strcmp(T->token,"VIRG") == 0)
				{
					//printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
		            desempilha(Pilha);
		            //T = T->prox;*****
		        }
		        if(strcmp(Pilha->inicio->palavra, ";") == 0 && strcmp(T->token,"PNT_VIRG") == 0)
				{
					//printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
			        desempilha(Pilha);
			        T = T->prox;
		        }
			}
			
			//TRATANDO A PRODUÇAO COMANDOS

			if(strcmp(Pilha->inicio->palavra, "COMANDOS") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
				desempilha(Pilha);

				if(strcmp(T->token, "ID") == 0 || strcmp(T->token, "LEIA") == 0 || strcmp(T->token, "ESCREVA") == 0)
				{
					empilha(Pilha, "COMANDO");
					printf("\n  + Empilhou o %s %s\n",Pilha->inicio->palavra, T->token);
					/*empilha(Pilha, ";");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, "COMANDOS");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);*/
				}
			}

			//TRATANDO A PRODUÇÃO COMANDO

			if(strcmp(Pilha->inicio->palavra, "COMANDO") == 0)
			{
				printf("\n  - Desempilhou o %s- %s\n",Pilha->inicio->palavra, T->token);
				desempilha(Pilha);

				if(strcmp(T->token,"ID") == 0)
				{
					empilha(Pilha, "EXP");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, ":=");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, "id");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
				}
				else if(strcmp(T->token,"LEIA") == 0)
				{
					empilha(Pilha, ")");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, "id");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, "(");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, "leia");	
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
				}
				else if(strcmp(T->token,"ESCREVA") == 0)
				{
					empilha(Pilha, ")");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, "id");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, "(");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, "escreva");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
				}

				if(strcmp(Pilha->inicio->palavra, "leia") == 0 && strcmp(T->token,"LEIA") == 0)
				{
					printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
			        desempilha(Pilha);
			        T = T->prox;
			    }
				if(strcmp(Pilha->inicio->palavra, "escreva") == 0 && strcmp(T->token,"ESCREVA") == 0)
				{
					printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
			        desempilha(Pilha);
			        T = T->prox;
			    }
			    if(strcmp(Pilha->inicio->palavra, "(") == 0 && strcmp(T->token,"ABRE_P") == 0)
				{
					printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
			        desempilha(Pilha);
			        T = T->prox;
			    }
		        if(strcmp(Pilha->inicio->palavra, "id") == 0 && strcmp(T->token,"ID") == 0)
				{
					printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
					desempilha(Pilha);
					T = T->prox;
				}
				if(strcmp(Pilha->inicio->palavra, ":=") == 0 && strcmp(T->token,"ATRIB") == 0)
				{
					printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
	                desempilha(Pilha);
	                T = T->prox;
	            }
	            if(strcmp(Pilha->inicio->palavra, ")") == 0 && strcmp(T->token,"FECHA_P") == 0)
				{
					printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
			        desempilha(Pilha);
			        T = T->prox;
			    }
	         
	            if(strcmp(T->prox->token,"FIM") != 0 && strcmp(Pilha->inicio->palavra,"EXP") != 0)
	            {
	            	/*empilha(Pilha, ";");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);*/
					empilha(Pilha, "COMANDOS");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);	
	            }
			}

			//TRATANDO A PRODUÇÃO EXP

			if(strcmp(Pilha->inicio->palavra, "EXP") == 0)
			{

				if(strcmp(T->prox->token,"ABRE_P") == 0 || strcmp(T->token,"ABRE_P") == 0)
				{
					printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
			    	desempilha(Pilha);

					empilha(Pilha, ")");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);	
					empilha(Pilha, "EXP");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					empilha(Pilha, "(");
					printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);		
				}
				else
				{
					if(strcmp(T->token,"PNT_VIRG") == 0)
					{
						empilha(Pilha, "EXP");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					}

					printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
			    	desempilha(Pilha);

					if(strcmp(T->token,"ID") == 0 && (strcmp(T->prox->token,"MULTIPLICACAO") == 0 || strcmp(T->prox->token,"ADICAO") == 0) || strcmp(T->prox->token,"SUBTRACAO") == 0)
					{
						empilha(Pilha, "EXP");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);	
						empilha(Pilha, "OP");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);	
						empilha(Pilha, "id");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);	
					}
					if(strcmp(T->token,"ID") == 0 && (strcmp(T->prox->token,"FECHA_P") == 0) || strcmp(T->prox->token,"PNT_VIRG") == 0)
					{	
						empilha(Pilha, "id");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);	
					}

					if(strcmp(T->token,"NUMERO") == 0 &&  (strcmp(T->prox->token,"MULTIPLICACAO") == 0 || strcmp(T->prox->token,"ADICAO") == 0) || strcmp(T->prox->token,"SUBTRACAO") == 0)
					{
						empilha(Pilha, "EXP");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);	
						empilha(Pilha, "OP");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
						empilha(Pilha, "num");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);	
					}
					if(strcmp(T->token,"NUMERO") == 0 && strcmp(T->prox->token,"FECHA_P") == 0)
					{
						empilha(Pilha, "num");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);	
					}
				}
			}
			 
			//TRATANDO A PRODUÇÃO OP

			if(strcmp(Pilha->inicio->palavra, "OP") == 0)
			{
				if(strcmp(T->prox->token,"ID") == 0 || strcmp(T->prox->token,"NUMERO") == 0 || strcmp(T->prox->token,"ABRE_P") == 0)
				{
					printf("\n  - Desempilhou o %s- %s\n",Pilha->inicio->palavra, T->token);
					desempilha(Pilha);

					if(strcmp(T->token,"ADICAO") == 0)
					{
						/*empilha(Pilha, "EXP");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);*/
						empilha(Pilha, "+");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					}
					else if(strcmp(T->token,"SUBTRACAO") == 0)
					{
						/*empilha(Pilha, "EXP");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);*/
						empilha(Pilha, "-");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					}
					else if(strcmp(T->token,"MULTIPLICACAO") == 0)
					{
						/*empilha(Pilha, "EXP");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);*/
						empilha(Pilha, "*");
						printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
					}
					else if(strcmp(T->token,"PNT_VIRG") == 0)
					{
						if(strcmp(T->prox->token,"FIM") == 0 || strcmp(T->prox->token,"COMANDOS") == 0)
			            {
							printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
				            desempilha(Pilha);
				            T = T->prox;
				        }
				        else
				        {
				        	empilha(Pilha, "COMANDO");
							printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
				        }
			        }
				}
			}

			if(strcmp(Pilha->inicio->palavra, "(") == 0 && strcmp(T->token,"ABRE_P") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
			    desempilha(Pilha);
			   // T = T->prox;
		    }

            if(strcmp(Pilha->inicio->palavra, "id") == 0 && strcmp(T->token,"ID") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
				desempilha(Pilha);
				//T = T->prox;
			}
            if(strcmp(Pilha->inicio->palavra, "num") == 0 && strcmp(T->token,"NUMERO") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
                desempilha(Pilha);
                //T = T->prox;
            }
            if(strcmp(Pilha->inicio->palavra, "+") == 0 && strcmp(T->token,"ADICAO") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
                desempilha(Pilha);
                //T = T->prox;
            }
            if(strcmp(Pilha->inicio->palavra, "-") == 0 && strcmp(T->token,"SUBTRACAO") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
                desempilha(Pilha);
                //T = T->prox;
            }
            if(strcmp(Pilha->inicio->palavra, "*") == 0 && strcmp(T->token,"MULTIPLICACAO") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
                desempilha(Pilha);
                //T = T->prox;
            }


            if(strcmp(Pilha->inicio->palavra, ";") == 0 && strcmp(T->token,"PNT_VIRG") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
	            desempilha(Pilha);
	        }
	        if(strcmp(Pilha->inicio->palavra, ";") == 0 && strcmp(T->prox->token,"FIM") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
	            desempilha(Pilha);
	        }
            if(strcmp(Pilha->inicio->palavra, "fim") == 0 && strcmp(T->token,"FIM") == 0)
			{
				printf("\n  - Desempilhou %s\n",Pilha->inicio->palavra);
                desempilha(Pilha);
            }
            if(strcmp(Pilha->inicio->palavra, ";") == 0 && strcmp(T->prox->token,"FIM") != 0)
			{
				/*empilha(Pilha, ";");
				printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);*/
				empilha(Pilha, "COMANDO");
				printf("\n  + Empilhou %s\n",Pilha->inicio->palavra);
            }

         	printf("\n XXX PILHA = %s - TOKEN = %s XXX\n",Pilha->inicio->palavra, T->token);

         	if(strcmp(Pilha->inicio->palavra, "$") == 0 && strcmp(T->token,"CIFRAO") == 0)
			{
				printf("\n  - Desempilhou %s\n\n",Pilha->inicio->palavra);
                desempilha(Pilha);
            }
		}
	}
}

int main(void)
{
	int TAM = 10;
	int Resposta = 0;


	//ANÁLISE LÉXICA
	
	listaDENC* Tokens = (listaDENC*)malloc(TAM*sizeof(listaDENC));

	Tokens = inicializalista();

	analisador_lexico(Tokens);

	imprimelista(Tokens);


	//ANÁLISE SINTÁTICA 

	pilha* Pilha = (pilha*)malloc(TAM*sizeof(pilha));

	Pilha = inicializapilha();

	analisador_sintatico(Tokens, Pilha);

	Resposta = pilha_vazia(Pilha);

	if(Resposta == 1)
	{
		printf("\n----------------------[ ACEITA ]-------------------------\n\n");
	}
	else
	{
        printf("\n----[ NAO ACEITA: Erro Sintático Em %s ]-----\n",Pilha->inicio->palavra);

        imprime_pilha(Pilha);

    }

    

	apaga_lista(Tokens);
	apaga_pilha(Pilha);
	
	return(0);
}