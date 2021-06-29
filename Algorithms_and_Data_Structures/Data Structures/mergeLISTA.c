#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 100

//LISTA DUPLAMENTE ENCADEADA ALOCADA DINAMICAMENTE

typedef struct celula{
	int conteudo;                  
	struct celula*prox;
	struct celula*ant;
}celula;

typedef struct listaDENC{				
	celula*inicio;
	int cont;
}listaDENC;

listaDENC *inicializa()
{
	listaDENC* l = (listaDENC*) malloc(sizeof(listaDENC));

	l->inicio = NULL;
	l->cont = 0;
	
	return l;
}

celula *cria(int conteudo)			
{
	celula *p = malloc(sizeof(celula));
	p->conteudo = conteudo;
	p->prox = NULL;
	p->ant = NULL;
	return p;
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

int insere_inicio(listaDENC *l, int conteudo)
{
	if(l == NULL)
	{
		return 0;
	}
	celula *novo = cria(conteudo);
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

int insere_fim(listaDENC *l, int conteudo)	
{
	if(l->inicio==NULL)
	{
		return(insere_inicio(l,conteudo));
	}
	
	celula *novo = cria(conteudo);

	if(novo==NULL)
	{
		return (0); //falso
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
	for(p = l->inicio;p != NULL;p = p->prox)
	{ 
      		printf("=> %d\n", p->conteudo);
	}
}
void imprime_lista (listaDENC *l)  		
{
	celula *p =l->inicio;
	
	while(p->prox != NULL)
	{ 
		printf("=> %d ", p->conteudo);
		p = p->prox;
		      		
	}
	printf("=> %d\n", p->conteudo);
}

void divide(lista *l, lista *L, lista *R)
{											//divide a lista em duas
    	
	int i,q;
	int i,p=l->inicio->conteudo;
	int r = l->fim->conteudo;						//p e r recebem os indices
    	
	celula *Q = l->inicio;									//nó para percorrer a lista
   
    	q=((r-p)/2)+1;
								//encontra o indice do meio
    	for(i=0; i<= q-1; i++)
	{							//percorre a lista até o meio
       		 Q = Q->prox;
    	}
    
	//atribui os valores respectivos para a lista da esquerda
   	L->inicio=l->inicio;
    	L->cont = q;
    	L->fim= Q->ant;
   
    	//atribui os valores respectivos para a lista da direita
    	R->inicio=Q;
    	R->cont = (r-p)-(q-1);
    	R->fim = l->fim;
   
} 

void Merge(listaDENC *l, listaDENC *LEFT, listaDENC *RIGHT)
{
    celula *left;							//nó para comparações da lista da esquerda
    celula *right;							//nó para comparações da lista da direita
    celula *list = l->inicio;						//nó para percorrer a lista

    inicializa(*L);							//lista para ser copiada a lista da esquerda
    inicializa(*R);							//lista para ser copiada a lista da direita
    int i=0;
   
    copylist(LEFT,L);							//copia o conteudo de LEFT para L
    copylist(RIGHT,R);							//copia o conteudo de RIGHT para R
   
    left = L->inicio;
    right = R->inicio;
   
    insere_inicio(L,9999);						//insere valor "infinito"
    insere_inicio(R,9999);
   
    for(i=0;i< l->cont; i++)
    {									//percorre toda a lista
        if(left->conteudo < right->conteudo)
	{								//compara se o valor da esquerda é maior que o valor da direita
            list->conteudo = left->conteudo;				//copia pra lista o valor da esquerda
            left = left->prox;						//avança para o proximo nó da esquerda;
        }
        else
	{
            list->conteudo = right->conteudo;				//copia o valor da direta para a lista
            right = right->prox;					//avança para o proximo nó da direita
        }
	
        list = list->prox;						//avança para o proximo nó da lista
    }
   
}

void MergeSort(listaDENC *l, int p, int r)
{
    
	listaSENC *L=inicializa();
    	listaSENC *R=inicializa();
    	
	if(r-p > 0)
	{

		divide(l, L, R);							//divide a lista em duas

		MergeSort(L, L->inicio->conteudo, L->fim->conteudo);			//faz recursão para a lista da esquerda
		MergeSort(R, R->inicio->conteudo, R->fim->conteudo);			//faz recursão para a lista da direita
		Merge(l,L,R);								//funde as listas
   	
	}

}

void concatena (listaSENC *l1, listaSENC *l2, listaSENC *l3)
{
	int i=0;
	int j=0;

	celula *novo1 = l1->inicio;
	celula *novo2 = l2->inicio;

	for(novo1 = l1->inicio; novo1 != NULL; novo1 = novo1->prox)
	{ 
		insere_inicio(l3, novo1->conteudo);
	}
	for(novo2 = l2->inicio; novo2 != NULL; novo2 = novo2->prox)
	{ 
		insere_inicio(l3, novo2->conteudo);
	}
	
}


int main(void)
{
	
	listaDENC* l1 = (listaDENC*)malloc(TAM*sizeof(listaDENC));
	listaDENC* l2 = (listaDENC*)malloc(TAM*sizeof(listaDENC));
	listaDENC* l3 = (listaDENC*)malloc(TAM*sizeof(listaDENC));
	l1 = inicializa();
	l2 = inicializa();
	l3 = inicializa();

	int i=0;
	int A,B,C;
	int conteudo;


	scanf("%d",&A);  
	for (i = 0; i < A; i++) 
	{
		scanf("%d",&conteudo);
		insere_inicio(l1, conteudo);
	}
	i=0;
	scanf("%d",&B);  
	for (i = 0; i < B; i++) 
	{
		scanf("%d",&conteudo);
		insere_inicio(l2, conteudo);
	}
	
	C=A+B;

	MergeSort(l1, l1->inicio, l1->fim);
	MergeSort(l2, l2->inicio, l2->fim);
	
	concatena(l1, l2, l3);
	MergeSort(l3, l3->inicio, l3->fim)

	imprime_lista (l3);

	apaga_lista (l1);
	apaga_lista (l1);
	apaga_lista (l3);
	return(0);

}
