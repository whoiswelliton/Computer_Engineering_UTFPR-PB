//TRABALHO 1 - Algoritmos e Estrutura de Dados II

//ALUNO - Welliton Leal

//GRAFO POR MEIO DE LISTAS DE ADJACÊNCIA ALOCADAS DINÂMICAMENTE

#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
	int content;           
	struct cell *next;
	struct cell *down;
}cell;

typedef struct list{
	int size;              
	struct cell *head;
	//struct cell *tail;
}list;
/*
typedef struct graphLADJ{
	list *vertex;
	list *edges; 
}graphLADJ;
*/
cell *new_CELL(int content)			
{
	cell *c = malloc(sizeof(cell));

	c->content = content;
	c->next = NULL;
	c->down = NULL;
	return c;
}

list *new_LIST()
{
	list *l = (list*) malloc(sizeof(list));
	
	l->head = NULL;
	//l->tail = NULL;
	l->size = 0;

	return l;
}

/*
graphLADJ *new_GRAPH()
{
	graphLADJ *G = (graphLADJ*)malloc(sizeof(graphLADJ));

	G->vertex = new_LIST();
	G->edges = new_LIST();

	return G;
}
*/

int verify_edge(list *e, int num)
{
	cell *p = malloc(sizeof(cell));

	for(p = e->head; p != NULL ; p = p->next)
	{ 
	      	if(p->content == num)
			{
				return 1;
			}
	}
	return 0;
}

int verify_vertex(list *v, int num)
{
	cell *p = malloc(sizeof(cell));

	for(p = v->head; p != NULL ; p = p->down)
	{ 
	      	if(p->content == num)
			{
				return 1;
			}
	}
	return 0;
}

int insert_vertex(list *v, int num)
{
	//se a lista estiver vazia, insere no inicio
	if(v->head == NULL) 
	{
		if(v == NULL)
		{
			return 0;
		}

		cell *new = new_CELL(num);

		if(new == NULL)
		{
			return 0;
		}

		new->content = num;
		new->down = v->head;
		new->next = NULL;
		v->head = new;
		//v->tail = new;
		v->size++;

		return 1; 
	}
	//lista não está vazia, verificar se já existe o vértice
	//senão existe, inserir 
	else
	{
		if(verify_vertex(v, num) == 0)
		{

			cell *new = new_CELL(num);

			if(new == NULL)
			{
				return (0); //falso
			}

			new->down = NULL;
			new->content = num;
			
			cell *last = v->head;

			while(last->down != NULL)
			{
				last = last->down;
			}

			last->down = new;
			v->size++;

			return 1; 
		}
		else
		{
			printf("\nEntrada Invalida, esse vertice ja existe!\n");
			return 0;
		}	
	}
}

int insert_edge2(list *v, list *e, int num)
{
	//se a lista estiver vazia, insere no inicio
	if(e->head == NULL) 
	{
		if(e == NULL)
		{
			return 0;
		}

		cell *new = new_CELL(num);

		if(new == NULL)
		{
			return 0;
		}

		new->content = num;
		new->down = NULL;
		new->next = e->head;
		e->head = new;
		//e->tail = new;
		e->size++;

		return(new);
	}
	//lista não está vazia, verificar se já existe o vértice
	//senão existe, inserir 
	else
	{
		if(verify_vertex(v, num) == 0)
		{

			cell *new = new_CELL(num);

			if(new == NULL)
			{
				return (0); //falso
			}

			new->next = NULL;
			new->down = NULL;
			new->content = num;
			
			cell *last = e->head;

			while(last->next != NULL)
			{
				last = last->next;
			}

			last->next = new;
			e->size++;

			return (new); 
		}
		else
		{
			printf("\nEntrada Invalida, esse vertice ja existe!\n");
			return 0;
		}	
	}
}

int insert_edge1(list *v, list *e, int num1, int num2)
{
	if(v->head == NULL) 
	{
		printf("\nNao existe nenhum vertice no grafo, impossivel adicionar aresta. \n");
	}
	//senão, inserir 
	else
	{
		//verificar se ambos os vértices existem
		if(verify_vertex(v, num1) == 0 && verify_vertex(v, num2) == 0)
		{
			//percorrendo lista vértices e inserindo aresta em V1 e V2
			cell *p = malloc(sizeof(cell));

			for(p = v->head; p != NULL ; p = p->down)
			{ 
			      	if(p->content == num1)
					{
						p->next = insert_edge2(v, e, num2);
					}	
					else if(p->content == num2)
					{
						p->next = insert_edge2(v, e, num1);
					}
			}
		}
		else
		{
			printf("\nEntrada Invalida, Algum dos Vertices inseridos nao existe!\n");
			return 0;
		}
		
	}
	
}

void print_list (list *l)  		
{
	cell *p;

	printf("\nGrafo:\n");
	for(p = l->head; p != NULL; p = p->next)
	{ 
      		printf("\n V[%d] |\n", p->content);
	}
}

void print_list2 (list *v, list *e)  		
{
	cell *p;

	printf("\nGrafo:\n");
	for(p = v->head; p != NULL; p = p->down)
	{ 
		printf("\n V[%d] |", p->content);

		cell *q;

		for(q = e->head; q != NULL; q = q->next)
		{ 
	      		printf(" %d =>", q->content);
		}
	}
	printf("\n");  
}

/*
void show_MENU(graphLADJ *G)
{
	int num = 0;

	while(num != 6)
	{
		printf("\n----------[MENU]----------\n\n");
		printf(" 1 - Inserir Vertice\n");
		printf(" 2 - Inserir Aresta\n");
		printf(" 3 - Visualizar Grafo\n");
		printf(" 4 - Remover Vertice\n");
		printf(" 5 - Remover Aresta\n");
		printf(" 6 - Sair\n");
		printf("--------------------------\n");
		printf("\n\nDigite uma das opcoes:");
		scanf("%d",&num);
	}
	system("cls");
}
*/

int main(void)
{
	/*
	graphLADJ *G = (graphLADJ*)malloc(sizeof(graphLADJ));

	G = new_GRAPH();

	show_MENU(G);

	//delete_GRAPH(G);
	*/

	list *V = (list*) malloc(sizeof(list));
	list *E = (list*) malloc(sizeof(list));

	V = new_LIST();
	E = new_LIST();

	insert_vertex(V, 1);
	insert_vertex(V, 2);
	insert_vertex(V, 3);
	insert_vertex(V, 5);
	insert_vertex(V, 5);

	print_list2(V, E);

	//insert_edge1(V, E, 1, 2);
	
	//print_list2(V, E);

	return 0;
}

/*
void delete_GRAPH(graphLADJ *G)
{
	
	//Apagando todas as células do tipo aresta
	cell *prev1 = G->edges->head;
	cell *current1 = G->edges->head;

	while (current1 != NULL)
	{
		prev1 = current1;
		current1 = current1->next;
		free(prev1);
	}

	G->edges->head = NULL;
	G->edges->tail = NULL;
	G->edges->size = 0;

	//Apagando todas as células do tipo vértice
	cell *prev2 = G->vertex->head;
	cell *current2 = G->vertex->head;

	while (current2 != NULL)
	{
		prev2 = current2;
		current2 = current2->down;
		free(prev2);
	}

	G->vertex->head = NULL;
	G->vertex->tail = NULL;
	G->vertex->size = 0;

	free(G);
}
*/