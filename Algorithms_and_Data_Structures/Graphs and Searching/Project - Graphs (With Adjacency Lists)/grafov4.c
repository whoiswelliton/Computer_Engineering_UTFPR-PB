//TRABALHO 1 - Algoritmos e Estrutura de Dados II

//ALUNO - Welliton Leal

//GRAFO POR MEIO DE LISTAS DE ADJACÊNCIA ALOCADAS DINÂMICAMENTE

#include<stdio.h>
#include<stdlib.h>

//ESTRUTURAS

typedef struct aresta
{
	int conteudo;           
	struct aresta *prox;
	struct aresta *ant;
}aresta;

typedef struct vertice
{
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
	aresta *a = v->inicio;

	while(a != NULL)
	{ 
	    if(a->conteudo == conteudo)
		{
			return 1;
		}
		a = a->prox;
	}
	return 0;
}

int verifica_vertice(grafo *g, int conteudo)
{
	vertice *v = g->inicio;

	while(v != NULL)
	{ 
	    if(v->conteudo == conteudo)
		{
			return 1;
		}
		v = v->prox;
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

			novo->ant = g->fim;

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
	vertice *v = g->inicio;

	while(v != NULL)
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

		v = v->prox;
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

	vertice *v = g->inicio;
	aresta *a = v->inicio;
	aresta *anterior;


	while(v != NULL)
	{ 
		if(v->conteudo == conteudo)
		{
			if(v->inicio == NULL)
			{
				printf("\n x Não existem arestas nesse vertice para serem apagadas\n");
			}
			else
			{
				a = v->inicio;
				
			    while(a != NULL)
			    {
			        anterior = a;
			        a = a->prox;

			        anterior = NULL;
			        free(anterior); 
			    }

			    v->inicio = NULL;
				v->fim = NULL;
				v->tam = 0;
				
				printf("\n x Todas as Arestas do Vertice [%d] Foram Apagadas\n",conteudo);
			}	
		}

		v = v->prox;
	}
}

void apaga_vertices(grafo *g)
{
	vertice *v = g->inicio;
	vertice *anterior;

	while(v != NULL)
	{ 
		apaga_arestas(g, v->conteudo);
		
		anterior = v;
		v = v->prox;

		anterior = NULL;
		free(anterior);
	}

	printf("\n x Todos os Vértices do Grafo Foram Apagados\n");
}

void apaga_grafo(grafo *g)
{
	apaga_vertices(g);

	g = NULL;
	free (g);

	printf("\n $ O GRAFO FOI APAGADO.\n\n");
}

//FUNÇÕES PARA REMOÇÃO DE ARESTAS E VÉRTICES

void remove_aresta1(grafo *g, int conteudo1, int conteudo2)
{

	vertice *v = g->inicio;
	aresta *a = v->inicio;
	aresta *anterior;

	while(v != NULL)
	{ 
		int removida = 0;

		if(v->conteudo == conteudo1)
		{

			if(v->tam == 1)
			{
					//printf("\n\nAchou o Vertice [%d]\n",v->conteudo);

					a = v->inicio;

					if(a->conteudo == conteudo2)
					{
						printf("Achou uma Aresta Unica na Lista do Vertice\n");
						removida = a->conteudo;

						a = NULL;
						free(a);

						//atualizo os apontadores do vértice
						v->inicio = NULL;
						v->fim = NULL;
						v->tam = 0;
					}	
			}
			else
			{
				
				a = v->inicio;

				while(a != NULL)
				{ 

					if(a->conteudo == conteudo2)
					{
						//printf("\n\nAchou o Vertice [%d]\n",v->conteudo);

						if(a == v->inicio)
						{
							printf("Achou a Aresta no Inicio da Lista do Vertice\n");
							removida = a->conteudo;

							a->prox->ant = NULL;
							v->inicio = a->prox;	//ou v->inicio->ant = NULL;
						}
						else if(a == v->fim)
						{
							printf("Achou a Aresta no Fim da Lista do Vertice\n");
							removida = a->conteudo;

							a->ant->prox = NULL;
							v->fim = a->ant;      //ou v->fim->prox = NULL;
						}
						else
						{
							printf("Achou a Aresta no Meio da Lista do Vertice\n");
							removida = a->conteudo;
		
							a->ant->prox = a->prox;
							a->prox->ant = a->ant;
						}

						v->tam--;

						anterior = a;
						a = a->prox;

						anterior = NULL;
						free(anterior);
					}
					else
					{
						a = a->prox;
					}
				}
			}

			if(removida != 0)
			{
				printf(" - Aresta %d Removida\n",removida);
			}
		}

		v = v->prox;
	}	
}

int remove_aresta2(grafo *g, int conteudo1, int conteudo2)
{
	if(g->inicio == NULL) 
	{
		printf("\n * Nao existe nenhum vertice no grafo, impossivel remover aresta. \n");
	}
	else
	{
		printf("\n\n-------------------------[REMOCAO DE ARESTA]-----------------------------\n\n");

		if(verifica_vertice(g, conteudo1) == 1 && verifica_vertice(g, conteudo2) == 1)
		{
			if(conteudo1 == conteudo2)	
			{
				printf("\n * Não Existe Loop no Vertice para ser Removido");
			}
			else
			{
				remove_aresta1(g, conteudo1, conteudo2);
				remove_aresta1(g, conteudo2, conteudo1);
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

	vertice *v = g->inicio;
	vertice *anterior;

	if(g->inicio == NULL) 
	{
		printf("\n * Nao existe nenhum vertice no grafo, impossivel remover vertices. \n");
	}
	else
	{
		if(verifica_vertice(g, conteudo) == 1)
		{
			printf("\n\n-------------------------[REMOCAO DE VERTICE]----------------------------\n\n");

			int removido = 0;

			if(g->tam == 1 && conteudo == v->conteudo)
			{
				v = g->inicio;

				printf("Achou um Vertice Unico\n");
				removido = v->conteudo;

				v = NULL;
				free(v);

				g->inicio = NULL;
				g->fim = NULL;
				g->tam = 0;
			}
			else
			{
				while(v != NULL)
				{ 
					if(v->conteudo == conteudo)
					{
						apaga_arestas (g, conteudo);

						if(v == g->inicio)
						{
							printf("Achou o Vertice no Inicio do Grafo\n");	
							removido = v->conteudo;

							v->prox->ant = NULL;
							g->inicio = v->prox;	//ou g->inicio->ant = NULL;
							g->tam--;
								
						}
						else if(v == g->fim)
						{
							printf("Achou o Vertice no Fim do Grafo\n");
							removido = v->conteudo;

							v->ant->prox = NULL;
							g->fim = v->ant;	//ou g->fim->prox = NULL; 
							g->tam--;
			
						}
						else
						{
							printf("Achou o Vertice no Meio da Grafo\n");
							removido = v->conteudo;

							v->ant->prox = v->prox;
							v->prox->ant = v->ant;
							g->tam--;
						}

						anterior = v;
					}
					else
					{
						remove_aresta1(g, v->conteudo, conteudo);
						
					}

					v = v->prox;

					anterior = NULL;
					free(anterior);	

				}
			}
			
			if(removido != 0)
			{
				printf("\n - Vertice [%d] Removido\n",removido);
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
	vertice *v = g->inicio;
	aresta *a;

	printf("\n\n-------------------------------[GRAFO]-----------------------------------\n\n");

	while(v != NULL)
	{ 
		printf("\n V[%d] | ", v->conteudo);

		if(v->inicio != NULL)
		{
			a = v->inicio;

			while(a != NULL)
			{ 
	      		printf("=> %d <=", a->conteudo);
	      		a = a->prox;
	      	}	
		}
		v = v->prox;
	}
		
	printf("\n\n");
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
	grafo *G = novo_grafo();

	//GRAFO TESTE TRABALHO
	
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
	
	remove_vertice(G, 2); 
	
	imprime_grafo(G);

	remove_aresta2(G, 3, 5); 

	imprime_grafo(G);

	Menu(G);
	
	apaga_grafo(G);

	return 0;
}