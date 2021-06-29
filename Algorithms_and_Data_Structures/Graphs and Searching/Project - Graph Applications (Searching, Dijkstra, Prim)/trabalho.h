#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include <float.h>
#define INFINITY 999999
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _node {       // Estruturas Do Grafo
    int vertex;            
	struct _edge* head; 
	struct _edge* tail;
	struct _node* up; 
	struct _node* bellow;
	int size;    
}node;
typedef struct _edge{
    int vertex; 
	int peso;          
	struct _edge* prev;  
    struct _edge* next;    
}edge;
typedef struct{
    node* head;
	node* tail;
	int size;
}grafo;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
grafo* new_grafo();       //Aloca memoria para um grafo      					OK
void free_grafo(grafo *g);//desaloca memoria e apaga o grafo 					OK

void insert_vertex(grafo* g,int value);	//funçoes de insersao de elementos		OK
void insert_edge(grafo* g,int v,int a,int p);	//								OK
void new_edge(node* n,int v,int p);//											OK
void new_vertex(grafo* g,int value);//											OK

void remove_vertex(grafo*g,int v); //funçoes de remoçao de elementos 			OK
void remove_edge(grafo* g,int v,int a);//										OK
void r_edge(node* n,edge* e);//													OK
void r_vertex(grafo* g,node* n);//												OK

bool exist_vertex(grafo* g,int v); //funçoes de verificaçao						OK
bool exist_edge(node* v,int e);		//											OK

edge* search_edge(node* v,int e);   //funçoes de busca							OK
node* search_vertex(grafo* g,int v);//											OK

int degree(grafo* g,int v); // função que retorna o grau de um vértice 			OK

void print_grafo(grafo* g); //imprimir o grafo									OK
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Estruturas Do vector Utilizado como auxiliar
typedef struct _elem {  // Cada nó possui armazena um valor e um ponteiro para o próximo.
	int v;
	int p;
	int d;
	int f;
	int c;
	node* end;
    struct _elem* next;
    struct _elem* prev;
}elem;
typedef struct {	// aponta para o primeiro nó na lista
    elem* head; 
    elem* tail;
    int size;
}vector;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Alocação e desalocação de memória
vector* new_vector();     											   			//OK		
void free_vector(vector* v); 													//OK
//funçoes de inserçao no vector
void vector_push_front(vector* v,node* end,int vert,int p,int d,int f,int c);	//OK

void vector_push_back(vector* v,node* end,int vert,int p,int d,int f,int c);	//OK

// Funções de remoção de elementos
void vector_pop_back(vector* v);												//OK

void vector_pop_front(vector* v);												//OK

//funçao para verificar se o vector esta vazio
bool vector_empty(vector* v);													//OK

//função para procurar o vertice no vetor	
elem* vector_search(vector* v,int vert); 										//OK

//função que retorna o inicio ou o fim do vector
elem* vector_head(vector* v);													//OK
elem* vector_tail(vector* v);

// busca um elemento marcado em branco no vetor auxiliar
int vector_white_search(vector* v);												//OK

// Impressão do valores no vetor 
void vector_print_dfs(vector* v);												//OK
void vector_print_bfs(vector* v);												//OK
void vector_print_prim(vector* v);												//OK
void vector_print_d(vector* v);													//OK

// funçao que extrai o minimo 													//OK
elem* extract_min(vector* v);													//OK
	
// funçao para verificar se o vertice existe no vetor
bool exist_vector(vector* v,int i);												//OK

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Função de busca em largura
void breadth_first_search(grafo* g, int v); 									//OK									

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funçao para busca em profundidade
void depth_first_search(grafo *g);												//OK

void dfs(vector* aux,int*f,int v);												//OK
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funçao para imprimir matriz de adjacencias
int busca_indice(grafo* g,int vert);											//OK

void matriz(grafo* g);															//OK
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funçao que verifica se o grafo é conexo
bool grafo_connected(grafo* g);													//OK
//funçao que construi a arvore geradora minima
void prim(grafo* g, int v);														//OK											
// constroi a arvore de caminho minimo de dijkstra
void dijkstra(grafo* g,int v);													//OK

	






