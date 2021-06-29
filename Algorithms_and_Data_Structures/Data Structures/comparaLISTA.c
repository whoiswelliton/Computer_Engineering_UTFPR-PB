#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//LISTA DUPLAMENTE ENCADEADA ALOCADA DINAMICAMENTE

typedef struct Item{
    char string;
    struct Item* prox;
    struct Item* ant;
}Item;

typedef struct Lista{
    int tamanho;
    struct Item* inicio;
    struct Item* fim;
}Lista;

Lista* novaLista()
{
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim    = NULL;
	l->tamanho = 0;

	return l;
}

Item* novoItem(const char c)
{
	Item *i = (Item*) malloc(sizeof(Item));
	i->string = c;
	i->prox = NULL;
	i->ant  = NULL;
	return i;
}


Item* ponteiroParaPosicao(Lista* l, int pos)
{
	Item* curr = NULL;

	if (pos < l->tamanho/2) {
		curr = l->inicio;
		for (int i = 0; i < pos - 1; ++i)
			curr = curr->prox;
	} else {
		curr = l->fim;
		for (int i = l->tamanho; i > pos; --i)
			curr = curr->ant;
	}

	return curr;
}


void inserirInicio(Lista* l, Item* novo)
{
	if (l->inicio == NULL) {
		l->inicio = novo;
		l->fim = l->inicio;
	} else {
		l->inicio->ant = novo;
		novo->prox = l->inicio;
		l->inicio = novo;
	}
	l->tamanho++;
}

void inserirProximo(Lista* l, Item* atual, Item* novo)
{
	assert(atual->prox != NULL);

	novo->prox = atual->prox;
	novo->ant = atual;

	atual->prox->ant = novo;
	atual->prox = novo;

	l->tamanho++;
}


void inserirFim(Lista* l, Item* novo)
{
	if (l->fim == NULL) {
		inserirInicio(l, novo);
	} else {
		l->fim->prox = novo;
		novo->ant = l->fim;
		l->fim = novo;
		l->fim->prox = NULL;

		l->tamanho++;
	}
}



void inserirNaPosicao(Lista* l, Item* novo, int pos)
{
	assert(pos >= 0 && pos <= l->tamanho);

	if (pos == 0)
		inserirInicio(l, novo);
	else if (pos == l->tamanho)
		inserirFim(l, novo);
	else {
		Item* curr = ponteiroParaPosicao(l, pos);
		inserirProximo(l, curr, novo);
	}
}



void printLista(Lista* l)
{
	Item* curr = l->inicio;
	while(curr != l->fim)
	{
		fprintf(stderr, "%d\t", curr->string);
		curr = curr->prox;
	}
	fprintf(stderr, "\n");
}

Lista* strParaLista (char* str)
{
    int i=0;
    Lista* l=novaLista();
    Item* e;
    while(str[i]!='\0'){
        e=novoItem(str[i]);
        inserirInicio(l,e);
        i++;
    }
    return l;
}

int strcmplist(Lista* A,Lista* B)
{
    int result;

    Item* curr;
    Item* curr1;

    curr=A->inicio;
    curr1=B->inicio;

    char a,b;
    while(curr!=NULL)
	{
        a=curr->string;
        b=curr1->string;

        if(a==b)
	{
            result=0;
        }
        else if(a<b)
	{
            result=-1;
            return result;
        }
        else if(a>b)
	{
            result=1;
            return result;
        }
        curr=curr->prox;
        curr1=curr1->prox;
    }
    return result;
}

int main() 
{
    char str[100];
    char str1[100];

    Lista* A=novaLista();
    Lista* B=novaLista();
    int result;

    scanf("%s",str);
    scanf("%s",str1);

    A=strParaLista(str);
    B=strParaLista(str1);
    result=strcmplist(A,B);

    if(result==0)
    {
       printf("A igual a B");
    }
    else if(result<0)
    {
        printf("A menor que B");
    }
    else if(result>0){
        printf("A maior que B");
    }

    return 0;
}
