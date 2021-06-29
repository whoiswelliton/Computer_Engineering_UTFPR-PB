#include <stdio.h>
#include <stdlib.h>

#define TAM 10    //tamanho para matriz quadrada

//MATRIZ ESPARSA ESTÁTICA COM LISTAS ENCADEADAS DINAMICAS


typedef struct celula{
	int conteudo;
	int linha, coluna;               
	struct celula*cima;
	struct celula*baixo;
	struct celula*prox;
	struct celula*ant;

}celula;

typedef struct lista{
	int indice;               
	struct celula*inicio;
	struct celula*fim;
	int cont;
}lista;

typedef struct Matriz{
	lista listalinhas[TAM];
	lista listacolunas[TAM];
}Matriz;

void inicializa_lista(lista *l,int k)
{
	l->indice = k;
	l->inicio = NULL;
	l->fim = NULL;
	l->cont = 0;
}

void inicializa_matriz(Matriz *M)
{
	int k=0;

	for (int k = 0; k < TAM; k++)
	{
		inicializa_lista(&M->listalinhas[k], k);
		inicializa_lista(&M->listacolunas[k], k);
	}
}

celula *cria(int conteudo, int i, int j)			
{
	celula *no = malloc(sizeof(celula));

	no->conteudo = conteudo;
	no->linha = i;
	no->coluna = j;
	no->prox = NULL;
	no->ant = NULL;
	no->cima = NULL;
	no->baixo = NULL;

	return no;
}

void apaga_lista (lista *l)
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
	l->cont = 0;
}

void apaga_matriz(Matriz *M)
{
	int k=0;

	for (int i = 0; i < TAM; i++)
	{
		apaga_lista(&(M->listalinhas[k]));
		apaga_lista(&(M->listalinhas[k]));
	}
}

int verifica_indices(int i, int j)
{
	if (i < 0 || i >= TAM || j < 0 || j >= TAM) 
	{
		printf("Índices (%d %d) fora das dimensões da matriz.\n", i, j);
		return 0;
	}
	return 1;
}

void insere_inicio_linha(Matriz *M, celula *novo, int i)
{
	if (M->listalinhas[i].inicio == NULL) 
	{
		M->listalinhas[i].inicio = novo;
		M->listalinhas[i].fim = M->listalinhas[i].inicio;
	} 
	else 
	{
		M->listalinhas[i].inicio->ant = novo;
		novo->prox = M->listalinhas[i].inicio;
		M->listalinhas[i].inicio = novo;
	}

	M->listalinhas[i].cont++;
}

void insere_inicio_coluna(Matriz *M, celula *novo, int j)
{
	if (M->listacolunas[j].inicio == NULL)
	{
		M->listacolunas[j].inicio = novo;
		M->listacolunas[j].fim = M->listacolunas[j].inicio;
	} else 
	{
		M->listacolunas[j].inicio->cima = novo;
		novo->baixo = M->listacolunas[j].inicio;
		M->listacolunas[j].inicio = novo;
	}

	M->listacolunas[j].cont++;
}

void insere_proximo_linha(Matriz *M, celula *atual, celula* novo, int i)
{
	if(atual->prox != NULL)
	{
		novo->prox = atual->prox;
		novo->ant = atual;

		atual->prox->ant = novo;
		atual->prox = novo;
	}

	M->listalinhas[i].cont++;
}

void insere_proximo_coluna(Matriz *M, celula *atual, celula* novo, int j)
{
	if(atual->baixo != NULL)
	{
		novo->baixo = atual->baixo;
		novo->cima = atual;

		atual->baixo->cima = novo;
		atual->baixo = novo;
	}

	M->listacolunas[j].cont++;
}

void insere_fim_linha(Matriz *M, celula* novo, int i)
{
	// Se lista vazia
	if (M->listalinhas[i].fim == NULL) 
	{
		insere_inicio_linha(M, novo, i);
	} 
	else 
	{
		M->listalinhas[i].fim->prox = novo;
		novo->ant = M->listalinhas[i].fim;
		M->listalinhas[i].fim = novo;
		M->listalinhas[i].fim->prox = NULL;
	
		M->listalinhas[i].cont++;
	}
}

void insere_fim_coluna(Matriz *M, celula* novo, int j)
{
	if (M->listacolunas[j].fim == NULL) 
	{
		insere_inicio_coluna(M, novo, j);
	} 
	else 
	{
		M->listacolunas[j].fim->baixo = novo;
		novo->cima = M->listacolunas[j].fim;
		M->listacolunas[j].fim = novo;
		M->listacolunas[j].fim->baixo = NULL;
	
		M->listacolunas[j].cont++;
	}
}

int insere_matriz(Matriz *M, int i, int j,int conteudo)
{
	if(i < TAM && j < TAM)
	{
		celula *novo = cria(conteudo, i, j); 

		//PARA INSERÇÃO NA LISTA ENCADEADA QUE REPRESENTA AS LINHAS

		if(M->listalinhas[i].inicio == NULL)
		{
			//linha vazia
			insere_inicio_linha(M, novo, i);
		}
		else
		{
			celula *aux = M->listalinhas[i].inicio; 
			
			while (aux != NULL && aux->coluna < j)
			{
				aux = aux->prox;
			}
			
			if (aux == NULL) 
			{
				insere_fim_linha(M, novo, i);
			} 
			else if (aux->coluna == j) 
			{
				aux->conteudo = conteudo;
			} 
			else if (aux == M->listalinhas[i].inicio)
			{
				insere_inicio_linha(M, novo, i);
			} 
			else 
			{
				insere_proximo_linha(M, aux->ant, novo, i); 
			}
		}

		//PARA INSERÇÃO NA LISTA ENCADEADA QUE REPRESENTA AS COLUNAS

		if(M->listacolunas[j].inicio == NULL)
		{
			//linha vazia
			insere_inicio_coluna(M, novo, j);
		}
		else
		{
			celula *aux = M->listacolunas[j].inicio; 
			
			while (aux != NULL && aux->linha < i)
			{
				aux = aux->baixo;
			}
			
			if (aux == NULL) 
			{
				insere_fim_coluna(M, novo, j);
			} 
			else if (aux->coluna == i) 
			{
				aux->conteudo = conteudo;
			} 
			else if (aux == M->listacolunas[j].inicio)
			{
				insere_inicio_coluna(M, novo, j);
			} 
			else 
			{
				insere_proximo_coluna(M, aux->ant, novo, i); 
			}
		}
	}
	return 0;
}

void imprime_matriz (Matriz *M)  		
{
	int i=0;
	celula *p;

	printf("\nMATRIZ ESPARSA APOS INSERCOES:\n");

	while(i < TAM)
	{
		printf("\nlinha[%d]",i);
		for(p = M->listalinhas[i].inicio; p != NULL; p = p->prox)
		{ 	      		
			printf(" => %d", p->conteudo);
		}
		i++;
	}
	printf("\n\n");

	i=0;

	while(i < TAM)
	{
		printf("\ncoluna[%d]",i);
		for(p = M->listacolunas[i].inicio; p != NULL; p = p->baixo)
		{ 	      		
			printf(" => %d", p->conteudo);
		}
		i++;
	}
	printf("\n\n");
}

int main(void)
{

	Matriz M; 

	inicializa_matriz(&M);

	//verifica_indices(i, j);

	//INSERINDO
	insere_matriz(&M, 0, 0, 10);
	insere_matriz(&M, 0, 4, 99);
	insere_matriz(&M, 0, 1, 876);
	insere_matriz(&M, 0, 9, 24);

	insere_matriz(&M, 3, 4, 56);
	insere_matriz(&M, 3, 3, 3);
	insere_matriz(&M, 3, 0, 14);

	

	imprime_matriz(&M);

	apaga_matriz(&M);
	
	return 0;
}
