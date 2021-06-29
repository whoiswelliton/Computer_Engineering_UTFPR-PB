//TRABALHO 1 - Algoritmos e Estrutura de Dados II

//ALUNO - Welliton Leal

//GRAFO POR MEIO DE LISTAS DE ADJACÊNCIA ALOCADAS DINÂMICAMENTE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITO 999999999

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

typedef struct celulalista
{
	int indice;
	int conteudo; 
	int chave;
	char cor;
	int pai;
	int tempo;
	int distancia;
	struct vertice *endereco;
	struct celulalista *prox;
	struct celulalista *ant;
}celulalista;

typedef struct lista
{				
	struct celulalista *inicio;
	struct celulalista *fim;
	int tam;
}lista;

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

//int tempo = 0;


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

lista *nova_lista()
{
	lista *l = (lista*) malloc(sizeof(lista));

	l->inicio = NULL;
	l->fim = NULL;
	l->tam = 0;
	
	return l;
}

celulalista *nova_celula_lista(vertice *endereco, int conteudo, int distancia, int pai, char cor, int tempo,int indice, int chave)			
{
	celulalista *c = malloc(sizeof(celulalista));

	c->endereco = endereco;
	c->conteudo = conteudo;
	c->distancia = distancia;  //descoberta
	c->tempo = tempo;         //finalização
	c->chave = chave;
	c->cor = cor;
	c->pai = pai;
	c->indice = indice;
	c->chave = chave;
	c->prox = NULL;
	c->ant = NULL;

	return c;
}

// FUNÇÕES PARA VERIFICAR SE A ARESTA OU VÉRTICE EXISTEM NA LISTA

int fila_vazia(fila *f)
{
	if(f == NULL || f->inicio == NULL)
	{
		//printf("\n  $ Fila Vazia.\n\n");
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

int verifica_branco(lista *l)
{
	celulalista *v = l->inicio;

	while(v != NULL)
	{ 
	    if(v->cor == 'B')
		{
			return 1;
		}
		v = v->prox;
	}
	return 0;
}

celulafila *busca_fila(fila *f, int conteudo)
{
	celulafila *c = f->inicio;

	while(c != NULL)
	{ 
	    if(c->conteudo == conteudo)
		{
			return c;
		}
		c = c->prox;
	}
}

celulalista *busca_lista(lista *l, int conteudo)
{
	celulalista *c = l->inicio;

	while(c != NULL)
	{ 
	    if(c->conteudo == conteudo)
		{
			return c;
		}
		c = c->prox;
	}
}

vertice *busca_vertice(grafo *g, int conteudo)
{
	vertice *v = g->inicio;

	while(v != NULL)
	{ 
	    if(v->conteudo == conteudo)
		{
			return v;
		}
		v = v->prox;
	}
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

int insere_lista(lista *l, vertice *endereco, int conteudo, int distancia, int pai, char cor, int tempo, int indice, int chave)	
{
	if(l->inicio == NULL)
	{
		celulalista *novo = nova_celula_lista(endereco, conteudo, distancia, pai, cor, tempo, indice, chave);

		if(novo == NULL)
		{
			return 0;
		}

		l->inicio = novo;
		l->fim = novo;
		l->tam++;

		return 1;

	}
	else
	{
		celulalista *novo = nova_celula_lista(endereco, conteudo, distancia, pai, cor, tempo, indice, chave);

		if(novo == NULL)
		{
			return (0);
		}

		l->fim->prox = novo;
		novo->ant = l->fim;
		l->fim = novo;
		l->tam++;

		return 1; 	
	}
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

		free(ant);
	}

	f->inicio = NULL;
	f->tam = 0;

	free(f);
}

void apaga_arestas(grafo *g, vertice *v)
{
	aresta *a;
	aresta *anterior;

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

			free(anterior); 
		}

		v->inicio = NULL;
		v->fim = NULL;
		v->tam = 0;
				
		printf("\n x Todas as Arestas do Vertice [%d] Foram Apagadas\n",v->conteudo);
	}	
	
}

void apaga_vertices(grafo *g)
{
	vertice *v = g->inicio;
	vertice *anterior;

	while(v != NULL)
	{ 
		apaga_arestas(g, v);
		
		anterior = v;
		v = v->prox;

		free(anterior);
	}

	printf("\n x Todos os Vértices do Grafo Foram Apagados\n");
}

void apaga_lista(lista *l)
{
	celulalista *c = l->inicio;
	celulalista *anterior;

	while(c != NULL)
	{ 
		anterior = c;
		c = c->prox;

		free(anterior);
	}

	free(l);
}

void apaga_grafo(grafo *g)
{
	printf("\n\n--------------------------[APAGANDO O GRAFO]-----------------------------\n");
	apaga_vertices(g);

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

		free(atual);
		return (removido);
	}
	else
	{
		removido = atual->conteudo;
		atual = f->inicio->prox;
		f->inicio = atual;
		
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
						apaga_arestas (g, v);

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

				}
			}

			free(anterior);	
			
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
	celulafila *cf = f->inicio;

	printf("\nFILA: ");
	while(cf != NULL)
	{
		printf(" %d <- ",cf->conteudo);
		cf = cf->prox;
	}
	printf("\n");

}

void imprime_lista(lista *l)
{
	celulalista *cf = l->inicio;

	printf("\nLista:\n");
	while(cf != NULL)
	{
		printf(" %d / %c /%d\n ",cf->conteudo, cf->cor, cf->chave);
		cf = cf->prox;
	}
	printf("\n");

}

void imprime_largura(lista *l)
{
	celulalista *cl = l->inicio;

	printf("[ vert \t|\tdist \t|\tpai \t|\tcor \t]\n");

	while(cl != NULL)
	{
		printf("[ v[%d]\t|\t%d\t|\t%d\t|\t%c\t]\n", cl->conteudo, cl->distancia ,cl->pai, cl->cor);
		cl = cl->prox;
	}
	printf("\n\n");
}

void imprime_profundidade(lista *l)
{
	celulalista *cl = l->inicio;

	printf("[ vert \t|\td[v] \t|\tf[v] \t|\tpi[v] \t]\n");

	while(cl != NULL)
	{
		printf("[ v[%d]\t|\t%d\t|\t%d\t|\t%d\t]\n", cl->conteudo, cl->distancia ,cl->tempo, cl->pai);
		cl = cl->prox;
	}
	printf("\n\n");
}

void imprime_prim(lista *l)
{
	celulalista *cl = l->inicio;

	printf("[ vert \t|\tpi[v] \t|\tkey[v]\t]\n");

	while(cl != NULL)
	{
		printf("[ v[%d]\t|\t%d\t|\t%d\t]\n", cl->conteudo, cl->pai, cl->chave);
		cl = cl->prox;
	}
	printf("\n\n");
}

void imprime_dijkstra(lista *l)
{
	celulalista *cl = l->inicio;

	printf("[ vert \t|\tpi[v] \t|\td[v] \t]\n");

	while(cl != NULL)
	{
		printf("[ v[%d]\t|\t%d\t|\t%d\t]\n", cl->conteudo, cl->pai, cl->chave);
		cl = cl->prox;
	}
	printf("\n\n");
}

//ALGORITMOS DE BUSCAS

lista *buscaemlargura (grafo *g, int s)
{
	if(s == -1)
	{
		s = g->inicio->conteudo;
	}
	
	int dis = 0;
	int pai = 0;

	printf("\n\n-------------------------[BUSCA EM LARGURA]----------------------------\n\n");

	if(verifica_vertice(g, s) == 1)
    {
    	fila *f = nova_fila();
		lista *l = nova_lista();

    	vertice *v = g->inicio;	
    	
		aresta *a = v->inicio;
    	celulalista *c;
    	celulalista *aux;
    	celulalista *atual;


    	while(v != NULL)
    	{
    		if(v->conteudo == s)
    		{
    			insere_lista(l, v, v->conteudo, 0, -1, 'C', 0, 0, 0);
    		}
    		else
    		{
    			insere_lista(l, v, v->conteudo, 0, 0, 'B' , 0, 0, 0);
    		}
			v = v->prox;
    	}
    	
   		enfila(f, s);

   		//imprime_fila(f);
		
 		while(fila_vazia(f) == 0)
 		{
 			
 			pai = desenfila(f);

 			atual = busca_lista(l, pai);

 			a = atual->endereco->inicio;

 			while(a != NULL)
 			{
 				aux = busca_lista(l, a->conteudo);
 				
 				if(aux->cor == 'B')
 				{
 					aux->cor = 'C';
 					aux->pai = pai;
 					aux->distancia = atual->distancia + 1;
 					
 					enfila(f, aux->conteudo);
 				}

		 		a = a->prox;
 			}

 			atual->cor = 'P';
 			
 			//imprime_fila(f);
 		}

 		apaga_fila(f);

 		return l;
    }
    else
    {
    	printf("\n\tVertice Inexistente.");
    }
}

int grafo_conexo (grafo *g)
{
	int qtd = 0;

	lista *l = buscaemlargura (g, -1);

	celulalista *c = l->inicio;

   	while(c != NULL)
    {
    	if(c->cor == 'B')
    	{
    		qtd++;
    	}
		c= c->prox;
   	}

   	if(qtd == 0)
   	{
   		apaga_lista(l);
   		printf("\n   O Grafo é Conexo!!\n\n");
   		return 1;
   	}
   	else
   	{
   		apaga_lista(l);
   		printf("\n   O Grafo é Desconexo!!\n\n");
   		return 0;
   	}


}


int profundidadevisita(grafo *g, celulalista *c, lista *l, int *cont)
{
	aresta *a = c->endereco->inicio;
	celulalista *aux;

	c->distancia = *cont;
	c->cor = 'C';

	while(a != NULL)
	{
		aux = busca_lista(l, a->conteudo);

		if(aux->cor == 'B')
		{
			aux->pai = c->conteudo;
			*cont = *cont + 1;
			//printf("%d\n",tempo);
			profundidadevisita(g, aux, l, cont);
		}

		a= a->prox;
	}
	
	*cont = *cont + 1;
	c->tempo = *cont;
	c->cor = 'P';
	
}

void buscaemprofundidade (grafo *g)
{
	printf("\n\n------------------------[BUSCA EM PROFUNDIDADE]-------------------------\n\n");

	int *cont = (int*)malloc(sizeof(int));
	*cont = 0 ;

	lista *l = nova_lista();

    vertice *v = g->inicio;	
    aresta *a = v->inicio;
    
    while(v != NULL)
    {
    	insere_lista(l, v, v->conteudo, 0, -1 , 'B', 0, 0, 0);
		v = v->prox;
   	}

   	celulalista *c = l->inicio;

   	while(c != NULL)
    {
    	if(c->cor == 'B')
    	{
    		*cont = *cont + 1;
    		profundidadevisita(g, c, l, cont);
    	}

		c= c->prox;
   	}
 
   	imprime_profundidade(l);
   	free(cont);
   	apaga_lista(l);
}

celulalista *extrair_min(lista *l)
{
	celulalista *c = l->inicio;
	celulalista *min;
	
	int menor = INFINITO;

	while(c != NULL)
	{
		if(c->chave < menor && c->cor == 'B')
		{
			menor = c->chave;
			min = c;
		}
		c = c->prox;
	}

	min->cor = 'P';

	return min;
}

void Algoritmo_de_Prim (grafo *g, int s)
{
	if(grafo_conexo(g) == 1)
	{
		printf("\n\n------------------------[ALGORITMO DE PRIM]-------------------------\n\n");

		lista *l = nova_lista();

	    vertice *v = g->inicio;	

	    //inicializo e insiro todos os vertices na lista auxiliar
	   
	    while(v != NULL)
	    {
	    		if(v->conteudo == s)
	    		{
	    			insere_lista(l, v, v->conteudo, 0, -1, 'B', 0, 0, 0);
	    		}
	    		else
	    		{
	    			insere_lista(l, v, v->conteudo, 0, 0, 'B' , 0, 0, INFINITO);
	    		}
				v = v->prox;
	    }

	    celulalista *min;
	    celulalista *aux;
	    aresta *a;

	 	while(verifica_branco(l) != 0)
	 	{
	 		min = extrair_min(l);

	 		a = min->endereco->inicio;

	 		while(a != NULL)
	 		{
	 			aux = busca_lista(l, a->conteudo);

	 			if(a->peso < aux->chave && aux->cor == 'B')
	 			{
	 				aux->chave = a->peso;
	 				aux->pai = min->conteudo;
	 			}

	 			a = a->prox;
	 		}
	 		
	 	}
	 	
	 	imprime_prim(l);
	 	apaga_lista(l);
	}
	else
	{
		printf("\nO Algoritmo de Prim nao pode ser executado, funciona apenas para grafos conexos, o grafo é desconexo.\n");
	}
	
}

void Algoritmo_de_Dijkstra (grafo *g, int s)
{
	printf("\n\n----------------------[ALGORITMO DE DIJKSTRA]-----------------------\n\n");

	lista *l = nova_lista();

	vertice *v = g->inicio;	
	   
	while(v != NULL)
	{
	    if(v->conteudo == s)
	    {
	    	insere_lista(l, v, v->conteudo, 0, -1, 'B', 0, 0, 0);
	    }
	    else
	    {
	    	insere_lista(l, v, v->conteudo, 0, 0, 'B' , 0, 0, INFINITO);
	    }
		v = v->prox;
	}

	celulalista *atual;
	celulalista *aux;
	aresta *a;

	while(verifica_branco(l) != 0)
	{
	 	atual = extrair_min(l);

	 	a = atual->endereco->inicio;

	 	while(a != NULL)
	 	{
	 		aux = busca_lista(l, a->conteudo);

	 		if((a->peso + atual->chave) < aux->chave && aux->cor == 'B')
	 		{
	 			aux->chave = a->peso + atual->chave;
	 			aux->pai = atual->conteudo;
	 		}

	 		a = a->prox;
	 	}
	}
	 	
	imprime_dijkstra(l);
	apaga_lista(l);
}

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

void matriz_adjacencia (grafo *g)
{
	printf("\n\n------------------------[MATRIZ ADJACENCIA]------------------------------\n\n");

	int indice = 0;
	int TAM = g->tam;
	int Matriz[TAM][TAM];

	for (int i = 0; i < TAM; ++i)
	{
		for (int j = 0; j < TAM; ++j)
		{
			Matriz[i][j] = 0;
		}
	}

	vertice *v = g->inicio;
	aresta *a;
	
	lista *l = nova_lista();
	
	while(v != NULL)
    {
    	indice++;
    	insere_lista(l, v, v->conteudo, -1, -1, 'B', -1, indice, 0);
		v = v->prox;
   	}

   	celulalista *c = l->inicio;

   	while(c != NULL)
   	{
   		a = c->endereco->inicio;

   		while(a != NULL)
   		{
   			celulalista *aux = busca_lista(l, a->conteudo);
   			Matriz[c->indice][aux->indice] = a->peso;
   			a = a->prox;
   		}

   		c = c->prox;
   	}

	//IMPRESSÃO DA MATRIZ

	int i, j;
	i = j = 0;
	printf("      ");
	while(i < TAM)
	{
		printf(" v[%d] ",i);
		i++;
	}

	printf("\n");
	
	i = j = 0;

	for(i = 0; i < TAM; i++)
	{
		printf("v[%d] |",i);

		for(j = 0; j < TAM; j++)
		{
			//Matriz[i][j] = 0;
			
			printf("  %.2d |", Matriz[i][j]);
		}
		printf("\n");
	}
	
	apaga_lista(l);
	printf("\n\n");
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
		else if(OP == 8)
		{
			matriz_adjacencia(G);
		}
		else if(OP == 9)
		{
			int s;
			printf("\nInforme um vertice existente no grafo para inicio: ");
			scanf("%d",&s);

			lista *l = buscaemlargura(G, s);

			imprime_largura(l);

			apaga_lista(l);
		}
		else if(OP == 10)
		{
			buscaemprofundidade(G);
		}
		else if(OP == 11)
		{
			int s;
			printf("\nInforme um vertice existente no grafo para inicio: ");
			scanf("%d",&s);
			Algoritmo_de_Dijkstra(G, s);
		}
		else if(OP == 12)
		{
			int s;
			printf("\nInforme um vertice existente no grafo para inicio: ");
			scanf("%d",&s);
			Algoritmo_de_Prim(G, s);
		}
		else if(OP == 0)
		{
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
	
	Menu(G);

	return 0;
}
