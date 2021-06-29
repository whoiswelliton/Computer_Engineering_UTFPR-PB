//TRABALHO 1 - Algoritmos e Estrutura de Dados II

//ALUNO - Welliton Leal

//GRAFO POR MEIO DE LISTAS DE ADJACÊNCIA ALOCADAS DINÂMICAMENTE


//  v ou a = NULL; // se abilitado, da pau, mas a professora insiste em dizer que não funciona no note dele por isso e que tem algo mais errado


#include<stdio.h>
#include<stdlib.h>

//ESTRUTURAS

typedef struct aresta{
	int conteudo;           
	struct aresta *prox;
	struct aresta *ant;
}aresta;

typedef struct vertice{
	int conteudo;
	struct aresta *inicio;
	struct aresta *fim;
	struct vertice *prox;
	struct vertice *ant;
	int tam;
}vertice;

typedef struct grafo
{
	struct vertice *inicio;
	struct vertice * fim;
	int tam;
}grafo;

//FUNÇÕES PARA CRIAR NOVA ARESTA, VÉRTICE E  GRAFO

aresta *nova_aresta(int conteudo)			
{
	aresta *a = malloc(sizeof(aresta));

	a->conteudo = conteudo;
	a->prox = NULL;
	a->ant = NULL;

	return a;
}

vertice *novo_vertice(int conteudo)
{
	vertice *v = (vertice*) malloc(sizeof(vertice));
	
	v->conteudo = conteudo;
	v->inicio = NULL;
	v->fim = NULL;
	v->prox = NULL;
	v->ant = NULL;
	v->fim = NULL;
	v->tam = 0;

	return v;
}

grafo *novo_grafo()
{
	grafo *g = (grafo*) malloc(sizeof(grafo));
	
	g->inicio = NULL;
	g->fim = NULL;
	g->tam = 0;

	return g;
}

// FUNÇÕES PARA VERIFICAR SE A ARESTA OU VÉRTICE EXISTEM NA LISTA

int verifica_aresta(vertice *v, int conteudo)
{
	aresta *a;

	for(a = v->inicio; a != NULL ; a = a->prox)
	{ 
	    if(a->conteudo == conteudo)
		{
			return 1;
		}
	}
	return 0;
}

int verifica_vertice(grafo *g, int conteudo)
{
	vertice *v;

	for(v = g->inicio; v != NULL ; v = v->prox)
	{ 
	    if(v->conteudo == conteudo)
		{
			return 1;
		}
	}
	return 0;
}

// FUNÇÕES PARA INSERÇÃO DE VÉRTICE E ARESTA

int insere_vertice(grafo *g, int conteudo)	
{
	if(g->inicio == NULL)
	{

		vertice *novo = novo_vertice(conteudo);

		if(novo == NULL)
		{
			return 0;
		}

		novo->conteudo = conteudo;
		novo->inicio = NULL;
		novo->fim = NULL;
		novo->prox = NULL;
		novo->ant = NULL;
		novo->tam = 0;

		g->inicio = novo;
		g->fim = novo;
		g->tam++;

		printf("\n + Vertice %d Inserido\n",novo->conteudo);

		return 1;
	}
	else
	{
		if(verifica_vertice(g, conteudo) == 0)
		{
			vertice *novo = novo_vertice(conteudo);

			if(novo == NULL)
			{
				return (0);
			}

			novo->conteudo = conteudo;
			novo->inicio = NULL;
			novo->fim = NULL;
			novo->prox = NULL;
			novo->ant = g->fim;
			novo->tam = 0;

			g->fim->prox = novo;
			g->fim = novo;
			g->tam++;

			printf(" + Vertice %d Inserido\n",novo->conteudo);

			return 1; 
			
		}
		else
		{
			printf(" * Entrada Invalida, O vertice %d ja Existe!\n",conteudo);
			return 0;
		}	
	}
}

int insere_aresta1(grafo *g, int conteudo1, int conteudo2)
{
	vertice *v;

	for(v = g->inicio; v != NULL ; v = v->prox)
	{ 
	    if(v->conteudo == conteudo1)
		{
			if(v->inicio == NULL)
			{
	
				aresta *nova = nova_aresta(conteudo2);

				if(nova == NULL)
				{
					return 0;
				}

				nova->conteudo = conteudo2;
				nova->prox = NULL;
				nova->ant = NULL;

				v->inicio = nova;
				v->fim = nova;
				v->tam++;

				printf(" + Aresta %d Inserida\n",nova->conteudo);

				return 1;
			}
			else
			{
				if(verifica_aresta(v, conteudo2) == 0)
				{
				
					aresta *nova = nova_aresta(conteudo2);

					if(nova == NULL)
					{
						return (0);
					}

					nova->conteudo = conteudo2;
					nova->prox = NULL;
					nova->ant = v->fim;

					v->fim->prox = nova;
					v->fim = nova;
					v->tam++;

					printf(" + Aresta %d Inserida\n",nova->conteudo);

					return 1; 
				}
				else
				{
					printf(" * Entrada Invalida, A Aresta %d ja Existe!\n",conteudo2);
					return 0;
				}	
			}
		}
	}
	return 0;
}

int insere_aresta2(grafo *g, int conteudo1, int conteudo2)
{
	if(g->inicio == NULL) 
	{
		printf("\n * Nao existe nenhum vertice no grafo, impossivel adicionar aresta. \n");
	}
	else
	{
		if(verifica_vertice(g, conteudo1) == 1 && verifica_vertice(g, conteudo2) == 1)
		{
			printf("\nOK - Verificao\n");

			if(conteudo1 == conteudo2)	
			{
				printf("\n * Nao é possivel inserir loops no grafo. \n");
			}
			else
			{
				insere_aresta1(g, conteudo1, conteudo2);
				insere_aresta1(g, conteudo2, conteudo1);
			}	
		}
		else
		{
			printf("\n * Entrada Invalida, Algum dos Vertices inseridos nao existe!");
			return 0;
		}
	}	
}

//FUNÇÕES PARA APAGAR TODASAS ARESTAS, VÉRTICES E O GRAFO POR COMPLETO

void apaga_arestas(grafo *g, int conteudo)
{

	vertice *v;

	for(v = g->inicio; v != NULL ; v = v->prox)
	{ 
		if(v->conteudo == conteudo)
		{
			if(v->inicio == NULL)
			{
				printf("\n x Não existem arestas nesse vertice para serem apagadas\n");
			}
			else
			{

				/*  OU USANDO WHILE
				aresta *atual = v->inicio;
				aresta *aux;

			    while(atual != NULL)
			    {
			        aux = atual;
			        atual = atual->prox;
			        free(aux);
			        //aux = NULL;
			    }

			    v->inicio = NULL;
				v->fim = NULL;
				v->tam = 0;*/
				
				
				aresta *atual = v->inicio;
				aresta *anterior = v->inicio;
				

				for(atual = v->inicio; atual != NULL ; atual = atual->prox)
				{ 
					anterior = atual;
					free(anterior);	
					//anterior = NULL;
				}
				v->inicio = NULL;
				v->fim = NULL;
				v->tam = 0;
				
				printf("\n x Todas as Arestas do Vertice [%d] Foram Apagadas\n",conteudo);
			}	
		}
	}
}

void apaga_vertices(grafo *g)
{
	vertice *v;

	for(v = g->inicio; v != NULL ; v = v->prox)
	{ 
		apaga_arestas(g, v->conteudo);
		free(v);
		//v = NULL;
	}
	printf("\n x Todos os Vértices do Grafo Foram Apagados\n");
}

void apaga_grafo(grafo *g)
{
	apaga_vertices(g);
	free (g);
	printf("\n $ O GRAFO FOI APAGADO.\n\n");
}

//FUNÇÕES PARA REMOÇÃO DE ARESTAS E VÉRTICES

void remove_aresta1(grafo *g, int conteudo1, int conteudo2)
{
	int removida = 0;

	vertice *v;

	for(v = g->inicio; v != NULL ; v = v->prox)
	{ 
		if(v->conteudo == conteudo1)
		{
			printf("\n\nAchou o Vertice [%d]\n",v->conteudo);

			aresta *a;

			for(a = v->inicio; a != NULL ; a = a->prox)
			{ 
				if(a->conteudo == conteudo2)
				{
					if(v->tam == 1)
					{
						printf("Achou a Aresta Unica na Lista Vertices\n");
						removida = a->conteudo;
						v->inicio = NULL;
						v->fim = NULL;
						v->tam = 0;

						free(a);
						//a = NULL;
					}
					else
					{
						if(a == v->inicio)
						{
							printf("Achou a Aresta no Inicio da Lista Vertices\n");
								
							removida = a->conteudo;
							a->prox->ant = NULL;
							v->inicio = a->prox;
							//ou v->inicio->ant = NULL;
							v->tam--;

							free(a);
							//a = NULL;
						}
						else if(a == v->fim)
						{
							printf("Achou a Aresta no Fim da Lista Vertices\n");

							removida = a->conteudo;
							a->ant->prox = NULL;
							v->fim = a->ant;
							//ou v->fim->prox = NULL;
							v->tam--;

							free(a);
							//a = NULL;
						}
						else
						{
							printf("Achou a Aresta no Meio da Lista Vertices\n");

							removida = a->conteudo;
							a->ant->prox = a->prox;
							a->prox->ant = a->ant;
							v->tam--;

							free(a);
							//a = NULL;
						}
					}
					printf(" - Aresta %d Removida\n",removida);
				}
			}
		}
	}	
}

int remove_aresta2(grafo *g, int conteudo1, int conteudo2)
{
	int flag1 = 0, flag2 = 0;
	vertice *v;

	if(g->inicio == NULL) 
	{
		printf("\n * Nao existe nenhum vertice no grafo, impossivel remover aresta. \n");
	}
	else
	{
		if(verifica_vertice(g, conteudo1) == 1 && verifica_vertice(g, conteudo2) == 1)
		{
			for(v = g->inicio; v != NULL ; v = v->prox)
			{ 
				if(verifica_aresta(v, conteudo1) == 1)
				{
					flag1 = 1;
				}
				else if(verifica_aresta(v, conteudo2) == 1)
				{
					flag2 = 1;
				}
			}

			if(conteudo1 == conteudo2)	
			{
				printf("\n * Não Existe Loop no Vertice para ser Removido");
			}
			else
			{
				if(flag1 == 1 && flag2 == 1)
				{
					remove_aresta1(g, conteudo1, conteudo2);
					remove_aresta1(g, conteudo2, conteudo1);
				}	
				else
				{
					printf("\n * Não Existe Aresta entre os Vertices Inseridos");
				}	
			}
		}
		else
		{
			printf("\n * Entrada Invalida, Algum dos Vertices inseridos nao existe!");
			return 0;
		}
	}	
}

void remove_vertice(grafo *g, int conteudo)
{
	int removido = 0;
	vertice *v;

	if(g->inicio == NULL) 
	{
		printf("\n * Nao existe nenhum vertice no grafo, impossivel remover vertices. \n");
	}
	else
	{
		if(verifica_vertice(g, conteudo) == 1)
		{
			for(v = g->inicio; v != NULL ; v = v->prox)
			{ 
				if(v->conteudo == conteudo)
				{
					apaga_arestas (g, conteudo);

					if(g->tam == 1)
					{
						printf("Achou a Vertice Unico\n");
						removido = v->conteudo;
						g->inicio = NULL;
						g->fim = NULL;
						g->tam = 0;
	
						free(v);
						//v = NULL;
					}
					else
					{
						if(v == g->inicio)
						{
							printf("Achou o Vertice no Inicio do Grafo\n");
								
							removido = v->conteudo;
							v->prox->ant = NULL;
							g->inicio = v->prox;
							//ou g->inicio->ant = NULL;
							g->tam--;
							
							free(v);
							//v = NULL; 
						}
						else if(v == g->fim)
						{
							printf("Achou o Vertice no Fim do Grafo\n");

							removido = v->conteudo;
							v->ant->prox = NULL;
							g->fim = v->ant;
							//ou g->fim->prox = NULL; 
							g->tam--;
							
							free(v);
							//v = NULL;
						}
						else
						{
							printf("Achou o Vertice no Meio da Grafo\n");

							removido = v->conteudo;
							v->ant->prox = v->prox;
							v->prox->ant = v->ant;
							g->tam--;
						
							free(v);
							//v = NULL;
						}
					
						printf(" - Vertice [%d] Removido\n",removido);
					}
				}
				else
				{
					remove_aresta1(g, v->conteudo, conteudo);
				}
			}
		}
		else
		{
			printf("\n * O Vertice Não Existe, Impossivel Remover");
		}
	}
}

// FUNÇÃO PARA IMPRESSÃO DO GRAFO NA TELA

void imprime_grafo(grafo *g)  		
{
	vertice *v;
	aresta *a;

	printf("\n\n-------------------------------[GRAFO]-----------------------------------\n\n");

	for(v = g->inicio; v != NULL; v = v->prox)
	{ 
		printf("\n V[%d] | ", v->conteudo);
		if(v->inicio != NULL)
		{
			for(a = v->inicio; a != NULL; a = a->prox)
			{ 
	      		printf("=> %d <=", a->conteudo);
	      	}

      		//printf("\n\n\tAresta Inicio: %d - Aresta Fim: %d\n",v->inicio->conteudo,v->fim->conteudo);
		}
	}
		
	printf("\n\n");
	//printf("O Grafo tem: %d Vertices.\n",g->tam);
	//printf("\n\tVertice Inicio: %d - Vertice Fim: %d\n\n",g->inicio->conteudo, g->fim->conteudo);
}

void Menu (grafo *G)
{
	int num = 0;

	do
	{
		int vert1 = 0;
		int vert2 = 0;

		printf("\n\n---------------------------------MENU-----------------------------------\n");
		printf("\n 1. Inserir Vertices");
		printf("\n 2. Inserir Arestas");
		printf("\n 3. Visualizar Grafo");
		printf("\n 4. Remover Vertices");
		printf("\n 5. Remover Arestas");
		printf("\n 6. Sair");
		printf("\n\nInforme a Opcao Desejada:");
		scanf("%d",&num);

		if(num == 1)
		{
			printf("\n - Digite o numero do vertice:\n");
			scanf("%d",&vert1);
			insere_vertice(G, vert1);
		}
		else if(num == 2)
		{
			printf("\n - Digite o número do primeiro vertice:\n");
			scanf("%d",&vert1);
			printf("\n - Digite o número do segundo vertice:\n");
			scanf("%d",&vert2);
			insere_aresta2(G, vert1, vert2);
		}
		else if(num == 3)
		{
			imprime_grafo(G);
			
		}
		else if(num == 4)
		{
			printf("\n - Digite o numero do vertice a ser removido:\n");
			scanf("%d",&vert1);
			remove_vertice(G, vert1);
		}
		else if(num == 5)
		{
			printf("\n - Digite o número do primeiro vertice da aresta a ser removida:\n");
			scanf("%d",&vert1);
			printf("\n - Digite o número do segundo vertice da aresta a ser removida:\n");
			scanf("%d",&vert2);
			remove_aresta2(G, vert1, vert2);
		}
		else if(num == 6)
		{
			printf("\n - Saindo...\n");
		}
		else
		{
			printf("\n * Opção nao Existe, Informe Novamente");
		}
		//system("pause");
		//system("clear");

	}while (num != 6);
}


int main(void)
{
	grafo *G;

	G = novo_grafo();

	//VÁRIOS TESTES A SEGUIR COM TODOS OS ERROS POSSÍVEIS

	/*
	printf("\n--------------------------------INSERÇÕES--------------------------------\n");
	
	insere_aresta2(G, 1, 5); //NÃO EXISTE NENHUM VÉRTICE

	insere_vertice(G, 1);
	insere_vertice(G, 2);
	insere_vertice(G, 3);
	insere_vertice(G, 4);
	insere_vertice(G, 5);
	insere_vertice(G, 6);

	insere_aresta2(G, 1, 2);
	insere_aresta2(G, 2, 3);
	insere_aresta2(G, 3, 4);
	insere_aresta2(G, 3, 5);
	insere_aresta2(G, 3, 1);
	insere_aresta2(G, 4, 2);

	insere_aresta2(G, 3, 3);   //NÃO É POSSÍVEL INSERIR LOOPS
	insere_aresta2(G, 1, 10);  //UM DOS VÉRTICES NÃO EXISTE

	imprime_grafo(G);

	printf("\n--------------------------------REMOÇÕES---------------------------------\n");
	
	remove_aresta2(G, 1, 5);  //NÃO EXISTE ARESTA ENTRE ELES
	remove_aresta2(G, 3, 6);  //NÃO EXISTE VÉRTICE EM UM DELES

	remove_aresta2(G, 1, 3);
	remove_aresta2(G, 2, 3);

	imprime_grafo(G);

	//apaga_arestas(G, 4);      //APAGA TODAS AS ARESTAS MAS NÃO REMOVE O VÉRTICE
	//imprime_grafo(G);

	remove_vertice(G, 3);     //APAGA O VÉRTICE E TODAS AS SUAS ARESTAS
	remove_vertice(G, 6);

	imprime_grafo(G);

	//apaga_vertices(G);		  //APAGA TODOS OS VÉRTICES E ARESTAS
	apaga_grafo(G);			  //APAGA O GRAFO POR COMPLETO
	
	//--------------------------------------------------------------------------
	*/

	//GRAFO TESTE PROFESSORA

	insere_vertice(G, 1);
	insere_vertice(G, 2);
	insere_vertice(G, 3);
	insere_vertice(G, 4);
	insere_vertice(G, 5);
	insere_vertice(G, 6);
	insere_vertice(G, 7);
	insere_vertice(G, 8);
	insere_vertice(G, 9);

	insere_aresta2(G, 1, 2);
	insere_aresta2(G, 1, 6);
	insere_aresta2(G, 2, 4);
	insere_aresta2(G, 2, 3);
	insere_aresta2(G, 4, 6);
	insere_aresta2(G, 4, 5);
	insere_aresta2(G, 4, 7);
	insere_aresta2(G, 5, 3);
	insere_aresta2(G, 7, 9);
	insere_aresta2(G, 7, 8);

	imprime_grafo(G);

	//remove_aresta2(G, 5, 3); 
	remove_vertice(G, 4); 

	imprime_grafo(G);

	//Menu(G);
	//apaga_grafo(G);

	return 0;
}