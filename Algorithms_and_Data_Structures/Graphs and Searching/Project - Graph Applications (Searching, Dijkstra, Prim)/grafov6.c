//TRABALHO 1 - Algoritmos e Estrutura de Dados II

//ALUNO - Welliton Leal

//GRAFO POR MEIO DE LISTAS DE ADJACÊNCIA ALOCADAS DINÂMICAMENTE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ESTRUTURAS

typedef struct aresta
{
	int conteudo;  
	int peso;         
	struct aresta *prox;
	struct aresta *ant;
}aresta;

typedef struct vertice
{
	int conteudo;
	char cor;
	int pai;
	int distancia;
	struct aresta *inicio;
	struct aresta *fim;
	struct vertice *prox;
	struct vertice *ant;
	int tam;
}vertice;

typedef struct grafo
{
	struct vertice *inicio;
	struct vertice *fim;
	int tam;
}grafo;

typedef struct celulafila
{
	int conteudo;            
	struct celulafila *prox;
}celulafila;

typedef struct fila
{				
	struct celulafila *inicio;
	struct celulafila *fim;
	int tam;
}fila;


//FUNÇÕES PARA CRIAR NOVA ARESTA, VÉRTICE, GRAFO, LISTA E FILA

grafo *novo_grafo()
{
	grafo *g = (grafo*) malloc(sizeof(grafo));
	
	g->inicio = NULL;
	g->fim = NULL;
	g->tam = 0;

	return g;
}

vertice *novo_vertice(int conteudo)
{
	vertice *v = (vertice*) malloc(sizeof(vertice));
	
	v->conteudo = conteudo;
	v->cor = 'B';
	v->distancia = 0;
	v->pai = 0;
	v->inicio = NULL;
	v->fim = NULL;
	v->prox = NULL;
	v->ant = NULL;
	v->tam = 0;

	return v;
}

aresta *nova_aresta(int conteudo, int peso)			
{
	aresta *a = malloc(sizeof(aresta));

	a->conteudo = conteudo;
	a->peso = peso;
	a->prox = NULL;
	a->ant = NULL;

	return a;
}

fila *nova_fila()
{
	fila *f = (fila*) malloc(sizeof(fila));

	f->inicio = NULL;
	f->fim = NULL;
	f->tam = 0;
	
	return f;
}

celulafila *nova_celula_fila(int conteudo)			
{
	celulafila *c = malloc(sizeof(celulafila));

	c->conteudo = conteudo;
	c->prox = NULL;

	return c;
}

// FUNÇÕES PARA VERIFICAR SE A ARESTA OU VÉRTICE EXISTEM NA LISTA

int fila_vazia(fila *f)
{
	if(f == NULL || f->inicio == NULL)
	{
		printf("\n   $ Fila Vazia.\n");
		return 1;
	}
	return 0;
}

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

int enfila(fila *f, int conteudo)
{
	if(f == NULL)
	{
		return 0;
	}

	celulafila *novo = nova_celula_fila(conteudo);

	if(novo == NULL)
	{
		return 0;
	}

	if(f->inicio == NULL)
	{
		f->inicio = novo;
		f->fim = novo;
	}
	else
	{
		f->fim->prox = novo;
		f->fim = novo;
	}

	f->tam++;

	return 1;
}

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

int insere_aresta1(grafo *g, int conteudo1, int conteudo2, int peso)
{
	vertice *v = g->inicio;

	while(v != NULL)
	{ 
	    if(v->conteudo == conteudo1)
		{
			if(v->inicio == NULL)
			{
				aresta *nova = nova_aresta(conteudo2, peso);

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
					aresta *nova = nova_aresta(conteudo2, peso);

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

int insere_aresta2(grafo *g, int conteudo1, int conteudo2, int peso)
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
				insere_aresta1(g, conteudo1, conteudo2, peso);
				insere_aresta1(g, conteudo2, conteudo1, peso);
			}	
		}
		else
		{
			printf("\n * Entrada Invalida, Algum dos Vertices inseridos nao existe!");
			return 0;
		}
	}	
}

//FUNÇÕES PARA APAGAR TODAS AS ARESTAS, VÉRTICES, O GRAFO POR COMPLETO, FILA E LISTA

void apaga_fila (fila *f)
{
	int i = 0;

	celulafila *ant = f->inicio;
	celulafila *atual = f->inicio;

	while (atual != NULL)
	{
		ant = atual;
		atual = atual->prox;

		ant = NULL;
		free(ant);
	}

	f->inicio = NULL;
	f->tam = 0;
}

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

//FUNÇÕES PARA REMOÇÃO DE ARESTAS, VÉRTICES, NÓS DE FILAS E LISTAS

int desenfila (fila *f)
{
	int removido;

	if(f == NULL || f->inicio == NULL)
	{
		printf(" * Nao ha elementos na Fila, Impossivel Remover.\n"); 
		return 0;
	}

	celulafila *ant = f->inicio;
	celulafila *atual = f->inicio;

	if(f->inicio == f->fim && f->tam == 1)
	{
		f->inicio = NULL;
		f->fim = NULL;
		f->tam = 0;
		removido = atual->conteudo;

		atual = NULL;
		free(atual);
		return (removido);
	}
	else
	{
		removido = atual->conteudo;
		atual = f->inicio->prox;
		f->inicio = atual;
		
		ant = NULL;
		free(ant);
		return (removido);
	}
	
}

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
						printf("\nAchou uma Aresta Unica na Lista do Vertice v[%d]\n",v->conteudo);
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
							printf("\nAchou a Aresta no Inicio da Lista do Vertice v[%d]\n",v->conteudo);
							removida = a->conteudo;

							a->prox->ant = NULL;
							v->inicio = a->prox;	//ou v->inicio->ant = NULL;
						}
						else if(a == v->fim)
						{
							printf("\nAchou a Aresta no Fim da Lista do Vertice v[%d]\n",v->conteudo);
							removida = a->conteudo;

							a->ant->prox = NULL;
							v->fim = a->ant;      //ou v->fim->prox = NULL;
						}
						else
						{
							printf("\nAchou a Aresta no Meio da Lista do Vertice v[%d]\n",v->conteudo);
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

				printf("\nAchou o Vertice v[%d] Como Unico no Grafo\n",v->conteudo);
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
							printf("\nAchou o Vertice v[%d] no Inicio do Grafo\n",v->conteudo);	
							removido = v->conteudo;

							v->prox->ant = NULL;
							g->inicio = v->prox;	//ou g->inicio->ant = NULL;
							g->tam--;	
						}
						else if(v == g->fim)
						{
							printf("\nAchou o Vertice v[%d] no Fim do Grafo\n", v->conteudo);
							removido = v->conteudo;

							v->ant->prox = NULL;
							g->fim = v->ant;	//ou g->fim->prox = NULL; 
							g->tam--;
						}
						else
						{
							printf("\nAchou o Vertice v[%d] no Meio da Grafo\n", v->conteudo);
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
				printf("\n - O Vertice v[%d] Foi Removido\n",removido);
			}
		}
		else
		{
			printf("\n * O Vertice Não Existe, Impossivel Remover");
		}
	}
}

// FUNÇÕES PARA IMPRESSÃO DE GRAFO, FILA E LISTA

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

void imprime_fila(fila *f)
{
	celulafila *c = f->inicio;

	printf("\nFILA: ");
	while(c != NULL)
	{
		printf(" -> %d  ",c->conteudo);
		c = c->prox;
	}
	printf("\n");

}

void imprime_busca_largura(grafo *g)
{
	vertice *v = g->inicio;

	printf("\n[\tvert \t|\tdist \t|\tpai \t|\tcor \t]\n");

	while(v != NULL)
	{
		printf("[\tv[%d]\t|\t%d\t|\t%d\t|\t%c\t]\n", v->conteudo, v->distancia ,v->pai, v->cor);
		v = v->prox;
	}

}

//ALGORITMOS DE BUSCAS

void buscaemlargura(grafo *g)
{
	int s;
	int pai;

	printf("\nInforme um vertice existente no grafo para iniciar a busca: ");
	scanf("%d",&s);

	printf("\n\n-------------------------[BUSCA EM LARGURA]----------------------------\n\n");

	if(verifica_vertice(g, s) == 1)
    {
    	int dis = 0;

		vertice *v = g->inicio;
		vertice *v2 = g->inicio;
		aresta *a = v->inicio;
		fila *f = nova_fila(f);

	  	while(v != NULL)
    	{
    		if(v->conteudo == s)
    		{
    			pai = v->conteudo;
    			
   				v->cor = 'C';
   				v->distancia = 0;
   				v->pai = -1; 	
   			}
   			else
   			{
   				v->cor = 'B';
   				v->distancia = 0;
   				v->pai = 0; 	
   			}
   			v = v->prox;
   		}

   		enfila(f, s);
	  
   		imprime_fila(f);
   		imprime_busca_largura(g);

   		dis++;
		pai = desenfila(f);

		printf("\nPAI: %d Distancia: %d\n",pai, dis);

		v = g->inicio;

		while(v != NULL)
	    {
	    	
	   		if(v->conteudo == s)
	   		{
	   			enfila(f, v->conteudo);
	   
	   			a = v->inicio;

			   	while(a != NULL)
			   	{
				   	v2 = g->inicio;
					
					while(v2 != NULL)
			   		{	

				  		if(a->conteudo == v2->conteudo)
				   		{
					   		v2->cor = 'C';
				 			v2->distancia = dis;
							v2->pai = pai;
							enfila(f, v2->conteudo);
							imprime_fila(f);
		   				}

		   				v2 = v2->prox;
		   			}
	
				   	a = a->prox;
				}

				v->cor = 'P';	   	
			}

	    	v = v->prox;
	    }
	   	
	   	dis++;
	   	pai = desenfila(f); 
	   	printf("\nPAI: %d Distancia: %d\n",pai, dis);
		imprime_fila(f);
   		imprime_busca_largura(g);


		while(fila_vazia(f) == 0)
		{
			v = g->inicio;

			pai = desenfila(f);

			while(v != NULL)
	    	{

	    		if(v->conteudo != s && v->cor == 'C')
	    		{
	    			a = v->inicio;

				   	while(a != NULL)
				   	{
					   	v2 = g->inicio;
						
						while(v2 != NULL)
				   		{	
					  		if(a->conteudo == v2->conteudo)
					   		{
					   			
					   			if(v2->cor == 'B')
					   			{
					   				
					   				v2->cor = 'C';
						 			v2->distancia = dis;
									v2->pai = pai;
									enfila(f, v2->conteudo);
									imprime_fila(f);
									imprime_busca_largura(g);
					   			}
						   		
			   				}

			   				v2 = v2->prox;
			   			}

					   	a = a->prox;
					}

					v->cor = 'P';
	    		}
	    		
	    		v = v->prox;	
	    	}
		     
		  	printf("\nPAI: %d Distancia: %d\n",pai, dis);
		  	dis++;
		}
		imprime_busca_largura(g);
	}
	else
    {
    	printf("\n\tVertice Inexistente.");
    }
}

//ALGORITMOS DE  CONSULTAS

void grau_vertice (grafo *g)
{
	vertice *v;
	int v_grau;	

	printf("\nInforme o Vertice que deseja saber o Grau: ");
	scanf("%d",&v_grau);

	printf("\n\n-------------------------------[GRAU]------------------------------------\n\n");

	if(verifica_vertice(g, v_grau) == 1)
	{
		for(v = g->inicio; v != NULL; v = v->prox)
		{ 
			if(v->conteudo == v_grau)
			{
				printf("\n -> O Grau do Vertice v[%d] e: %d \n\n",v_grau,v->tam);
			}
		}
	}
	else
	{
		printf("\n * Vertice Inexistente.");
	}	
}

void grafo_conexo (grafo *g)
{

}

//MENU DE OPÇÕES	

void Menu (grafo *G)
{
	int OP = 0;

	do
	{
		int vert1 = 0;
		int vert2 = 0;
		int peso = 0;

		printf("\n\n--------------------------------[MENU]-----------------------------------\n");
		printf("\n 1. Inserir Vertice");
		printf("\n 2. Inserir Aresta");
		printf("\n 3. Visualizar Grafo");
		printf("\n 4. Remover Vertices");
		printf("\n 5. Remover Arestas");
		printf("\n 6. Grau de um Vertice");
		printf("\n 7. Informar se o Grafo e Conexo");
		printf("\n 8. Converter para Matriz de Adjacência");
		printf("\n 9. Busca em Largura");
		printf("\n 10. Busca em Profundidade");
		printf("\n 11. Caminho Minimo (Algoritmo de Dijkstra)");
		printf("\n 12. Arvore Geradora Minima (Algoritmo de Prim)");
		printf("\n 0. Sair");
		printf("\n\nInforme a Opcao Desejada:");
		scanf("%d",&OP);

		if(OP == 1)
		{
			printf("\n - Digite o numero do vertice:\n");
			scanf("%d",&vert1);
			insere_vertice(G, vert1);
		}
		else if(OP == 2)
		{
			printf("\n - Digite o número do primeiro vertice:\n");
			scanf("%d",&vert1);
			printf("\n - Digite o número do segundo vertice:\n");
			scanf("%d",&vert2);
			printf("\n - Digite o peso/distancia da aresta:\n");
			scanf("%d",&peso);

			if(peso > 0)
			{
				insere_aresta2(G, vert1, vert2, peso);
			}
			else
			{
				printf("\n x Digite um Peso Maior que Zero.\n");
			}
			
		}
		else if(OP == 3)
		{
			imprime_grafo(G);
			
		}
		else if(OP == 4)
		{
			printf("\n - Digite o numero do vertice a ser removido:\n");
			scanf("%d",&vert1);
			remove_vertice(G, vert1);
		}
		else if(OP == 5)
		{
			printf("\n - Digite o número do primeiro vertice da aresta a ser removida:\n");
			scanf("%d",&vert1);
			printf("\n - Digite o número do segundo vertice da aresta a ser removida:\n");
			scanf("%d",&vert2);
			remove_aresta2(G, vert1, vert2);
		}
		else if(OP == 6)
		{
			grau_vertice(G);
		}
		else if(OP == 7)
		{
			grafo_conexo(G);
		}





		else if(OP == 0)
		{
			printf("\n - Saindo...\n");
			apaga_grafo(G);
		}
		else
		{
			printf("\n * Opção nao Existe, Informe Novamente");
		}

	}while(OP != 0);
}


int main(void)
{
	grafo *G = novo_grafo();

	insere_vertice(G, 1);
	insere_vertice(G, 2);
	insere_vertice(G, 3);
	insere_vertice(G, 4);
	insere_vertice(G, 5);
	insere_vertice(G, 6);
	insere_vertice(G, 7);
	insere_vertice(G, 8);
	insere_vertice(G, 9);
	insere_vertice(G, 10);

	insere_aresta2(G, 1, 2, 7);
	insere_aresta2(G, 1, 4, 9);
	insere_aresta2(G, 1, 5, 10);
	insere_aresta2(G, 1, 6, 8);
	insere_aresta2(G, 1, 8, 9);
	insere_aresta2(G, 1, 10, 8);
	insere_aresta2(G, 2, 3, 4);
	insere_aresta2(G, 2, 4, 5);
	insere_aresta2(G, 2, 9, 9);
	insere_aresta2(G, 2, 10, 9);
	insere_aresta2(G, 3, 4, 1);
	insere_aresta2(G, 3, 5, 4);
	insere_aresta2(G, 4, 5, 3);
	insere_aresta2(G, 5, 6, 18);
	insere_aresta2(G, 6, 7, 9);
	insere_aresta2(G, 6, 8, 9);
	insere_aresta2(G, 7, 8, 3);
	insere_aresta2(G, 7, 9, 6);
	insere_aresta2(G, 8, 9, 4);
	insere_aresta2(G, 8, 10, 2);
	insere_aresta2(G, 9, 10, 2);

	imprime_grafo(G);

	buscaemlargura(G);

	//Menu(G);

	//apaga_grafo(G);
	return 0;
}
