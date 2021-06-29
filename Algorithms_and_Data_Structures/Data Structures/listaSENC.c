#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//LISTA SIMPLESMENTE ENCADEADA ALOCADA DINAMICAMENTE

typedef struct celula{
	int conteudo;    
	//char info[30];             
	struct celula*prox;
}celula;
typedef struct listaSENC{				
	celula*inicio;
	int cont;
}listaSENC;

void inicializa(listaSENC *l)
{
	l->inicio = NULL;
	l->cont = 0;
}

celula *cria(int conteudo)			
{
	celula *p = malloc(sizeof(celula));
	p->conteudo = conteudo;
	p->prox = NULL;
	return p;
}

int lista_vazia(listaSENC *l)
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

int insere_inicio(listaSENC *l, int conteudo)
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

	novo-> conteudo = conteudo;
	novo->prox = l->inicio;
	l->inicio = novo;
	l->cont++;
	return 1;
}

int insere_fim(listaSENC *l, int conteudo)	
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
	novo->prox = NULL;
	novo->conteudo = conteudo;
	
	celula *ultimo = l->inicio;

	while(ultimo->prox !=NULL)
	{
		ultimo=ultimo->prox;
	}

	ultimo->prox=novo;
	l->cont++;
	return 1; 
}
int insere_pos(listaSENC *l, int conteudo, int pos)
{
	if(pos > l->cont+1 || pos < 0) 
	{
		return 0;
	}
	if(pos == l->cont+1)
	{
		insere_fim(l,conteudo)	;
	}
	if(l->inicio == NULL || pos <= 0)
	{
		return(insere_inicio(l,conteudo));
	}


	celula *novo = cria(conteudo);
	celula *aux = l->inicio;
	
	if(l->cont == 0)
	{
		novo->conteudo = aux->conteudo;
		novo->prox = l->inicio;
		l->inicio = novo;
		l->cont++;
		return 1;
	}
	for(pos--; pos > 1; aux = aux->prox, pos--)
	{
		if(aux == NULL){
			free(novo);
			novo = NULL;
			return 0;
		}
	}

	novo->prox = aux->prox;
	aux->prox = novo;
	l->cont++;
	return 1;
}


int insere_ordenado (listaSENC *l, int conteudo)
{
	
	celula *novo = cria(conteudo);
	
	if(novo==NULL || l == NULL)
	{
		return 0;
	}

	novo->conteudo = conteudo;

	if(l->inicio==NULL)
	{
		return(insere_inicio(l,conteudo));
	}
	else
	{
		celula *ant = l->inicio;
		celula *atual = l->inicio;

		while(atual != NULL && atual->conteudo < conteudo)
		{
			ant = atual;
			atual = atual->prox;
		}
		if(atual == l->inicio)
		{
			return(insere_inicio(l,conteudo));
		}
		else
		{
			novo->prox = atual;
			ant->prox = novo;
		}
	}

	l->cont++;
	return 1;
}

int remove_inicio(listaSENC *l)
{
	if(l == NULL || l->inicio == NULL)
	{
		return 0;
	}

	int ret = l->inicio->conteudo;
	
	celula *rmv = l->inicio;
	l->inicio = l->inicio->prox;
	free(rmv);
	l->cont--;
	return(ret);
}

int remove_fim (listaSENC *l)
{
	if(l == NULL || l->inicio == NULL)
	{
		return 0;
	}
	celula *ant = l->inicio;
	celula *novo = l->inicio;
	while(novo->prox != NULL)
	{
		ant = novo;
		novo = novo->prox;
	}
	if(novo == l->inicio)
	{
		l->inicio = novo->prox;
	}
	else
	{
		ant->prox = novo->prox;
	}

	free(novo);
	l->cont--;
	return 0;

}

int remove_elemento (listaSENC *l, int conteudo)
{
	if(l == NULL || l->inicio == NULL)
	{
		return 0;
	}

	celula *ant = l->inicio;
	celula *novo = l->inicio;

	while(novo != NULL && novo->conteudo != conteudo)
	{
		ant = novo;
		novo = novo->prox;
	}
	if (novo == NULL) //não encontrado
	{
		return 0;
	}
	if (novo == l->inicio)
	{
		l->inicio = novo->prox;
	}
	else
	{
		ant->prox = novo->prox;
	}

	free(novo);
	l->cont--;
	return 0;
}

int remove_pos(listaSENC *l, int pos)
{
	if(l == NULL || l->inicio == NULL || pos > l->cont)
	{
		return 0;
	}												
	if(pos == 0)
	{
		remove_inicio(l);
	}

	celula *ant = l->inicio;
	celula *novo = l->inicio;

	int i=0;

	while(i < pos)
	{
		ant = novo;
		novo = novo-> prox;
		i++;
	}

	ant->prox = novo->prox;

	free(novo);
	l->cont--;
	return 1;
}

celula *busca_posicao (listaSENC *l, int pos)
{

	celula *novo = l->inicio;

	if(pos == 0)
	{
		return l->inicio;
	}
	if(l == NULL || pos < 0 || pos >= l->cont)
	{
		novo->conteudo = -1;
		return novo;
	}

	int i=0;

	for (i = 0; i < pos; i++)
	{
		novo = novo->prox;
	}

	return novo;
}

int busca_conteudo (listaSENC *l, int conteudo)
{
	if(l == NULL)
	{
		return 0;
	}

	celula *novo = l->inicio;

	int i=0;

	while(novo != NULL)
	{
		if(novo->conteudo == conteudo)
		{
			return i;
		}
		novo = novo->prox;
		i++;
	}
	return -1;
}

void imprime_lista (listaSENC *l)  		
{
	celula *p;
	for(p = l->inicio;p != NULL;p = p->prox)
	{ 
      		printf(" %d ", p->conteudo);
	}
}

void apaga_lista (listaSENC *l)
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

/*
int merge_LD(LD *L1, LD *L2)
{
    no* aux;
    no* aux2, *tmp;
    if(L1->nelem==0 && L2->nelem==0)
    {
        return(-1);
    }
    aux=L1->inicio;
    aux2=L2->inicio;
    int i;
    int j=L2->nelem;
    for(i=1;i<=j;i=i++)
    {
        aux = aux->prox;
        tmp = aux2->prox;
        inserirPosicao(L1,i*2,aux2);
        aux2 = tmp;
    }
    return 1;
}
*/

/*
void verificar_menor(LD* L1)
{
    no* aux;
    no* menor;
    aux=L1->inicio;
    menor = L1->inicio;
    while(aux != NULL)
    {
        if(aux->chave < menor->chave)
        {
            menor = aux;
        }
        aux = aux->prox;
    }
    printf("Chave menor e: %d", menor->chave);
}
*/

/*
int inverterLista(LD *L)
{
    if(L->nelem == 0)
    {
        return -1;
    }
    else
    {
        int cont;
        int trocas = 0;
        int posicao = 1;
        no *aux, *aux2;
        while(trocas <= (L->nelem))
        {
            aux = L->inicio;
            L->inicio = aux->prox;;
            aux2 = L->inicio;
            cont = 1;
            while(cont < (L->nelem - posicao))
            {
                cont++;
                aux2 = aux2->prox;
            }
            aux->prox = aux2->prox;
            aux2->prox = aux;
            if(trocas == 0)
            {
                L->fim = aux;
            }
            trocas++;
            posicao++;
        }
        return 1;
    }
}
*/

/*
void imprimirIguais(LD *L, LD *L2)
{
    no *aux1, *aux2;
    int cont = 0;
    int cont2 = 0;
    int res = 0;

    aux1 = L->inicio;
    if(L->nelem == 0 || L2->nelem == 0)
    {
        printf("\nNao ha elemento iguais para imprimir");
    }
    else
    {
        while(aux1 != NULL)
        {
            aux2 = L2->inicio;
            while(aux2 != NULL)
            {
                if(aux1->chave == aux2->chave)
                {
                    res = compararStrings(aux1->info, aux2->info, 0);
                    if(res == 1)
                    {
                        printf("\nChave L1: %d / Info: %s", aux1->chave, aux1->info);
                        printf("\nChave L2: %d / Info: %s\n", aux2->chave, aux2->info);
                    }

                }
                aux2 = aux2->prox;
            }
            aux1 = aux1->prox;
        }
    }
}

*/




int main(void)
{
	listaSENC l,l1,l2, l3;
	int i=0;
	int aux=0;

	celula *A = cria(0);


	inicializa(&l);
	inicializa(&l1);
	inicializa(&l2);
	inicializa(&l3);

	
	for (i = 0; i < 10; ++i)
	{
		insere_inicio(&l, i);              //ok
		insere_ordenado(&l, rand()%10); 

		insere_inicio(&l1, rand()%10);
		insere_inicio(&l2, rand()%10);
	}

	insere_fim(&l, 100);              //ok

	insere_pos(&l, 500, -1);        //ok

	printf("\n");

	imprime_lista (&l);

	printf("\n-> APOS REMOVER:\n\n");

	remove_inicio(&l);

	remove_elemento (&l, 100);

	remove_fim (&l);

	remove_pos (&l, 8);
	
	imprime_lista (&l);

	printf("\n-> APOS BUSCAS:\n");

	A = busca_posicao (&l, 5); 

	if(A->conteudo != -1)
	{
		printf("\n*Conteudo Encontrado na Posicao: %d \n",A->conteudo);
	}
	else
	{
		printf("\n*Posicao fora do intervalo da lista\n");
	}
	
	aux = busca_conteudo(&l, 5);
	
	if(aux != -1)
	{
		printf("\n*Posicao Encontrada com o Conteudo: %d \n",aux);
	}
	else
	{
		printf("\n*Conteudo nao Encontrado na Lista\n");
	}

	printf("\n-> MERGE SORT:\n");

	imprime_lista (&l1);
	printf("\n\n");
	imprime_lista (&l2);
	printf("\n\n");

	/*
	l3 = merge (&l1, &l2);
	printf("Lista Concatenada:\n");
	imprime_lista (&l3);
	printf("\n");
	*/

	apaga_lista (&l);

	return(0);
}



//ARQUIVO MORTO COM FUNÇÕES POSSÍVEIS

/*

int removerPorChave(LD *L, int chave)
{
    no *aux1;
    no *aux2;
    int i=0;
    int k=0;

    aux1 = L->inicio;
    aux2 = aux1->prox;

    if(aux1->chave == chave)
    {
        L->inicio = aux2;
        free(aux1);
        aux1 = NULL;
        L->nelem--;
        return 1;
    }
    while(aux1->prox != NULL && aux1->chave != chave)
    {
        aux1 = aux1->prox;
        i++;
    }
    if(aux1->prox == NULL && aux1->chave != chave)
    {
        printf("\nNao ha esta chave para remover.\n");
        return -1;
    }
        aux1 = L->inicio;
        aux2 = aux1->prox;
        while(k < i-1)
        {
            aux1 = aux1->prox;
            aux2 = aux1->prox;
            k++;
        }
            //aux2 = aux1->prox;
            aux1->prox=aux2->prox;
            free(aux2);aux2=NULL;
            L->nelem--;
            return 1;

}
*/

/*
int compararStrings(char info1[], char info2[], int cont1)
{
    int res = 0;
    int x, y;
    x = strlen(info1);
    y = strlen(info2);
    while(info1[cont1] != '\0' && info2 != '\0')
    {
        if(info1[cont1] == info2[cont1])
        {
            res++;
        }
        cont1++;
    }
    if(x = y)
    {
        if(res = x && res == y)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}
*/

/*
void unirListas(LD *L, LD *L2)
{
    no *aux, *aux2, *temp;
    if(L->nelem == 0 && L2->nelem == 0)
    {
        printf("\nNao ha elementos para unir.\n");
    }
    else
    {
        aux = L->inicio;
        aux2 = L2->inicio;
        int i;
        for(i = 1; i <= L2->nelem; i++)
        {
            aux = aux->prox;
            temp = aux2->prox;
            inserirPosicao(L, i*2, aux2);
            aux2 = temp;
        }
    }
}
*/
/*
void unirListasOrdenado(LD *L, LD *L2)
{
    no *aux, *aux2, *temp;
    if(L->nelem == 0 && L2->nelem == 0)
    {
        printf("\nNao ha elementos para unir.\n");
    }
    else
    {
        aux = L->inicio;
        aux2 = L2->inicio;
        int i;
        for(i = 1; i <= L2->nelem; i++)
        {
            aux = aux->prox;
            temp = aux2->prox;
            if(aux->chave > aux->prox->chave)
            {
                inserirPosicao(L, (i*2 + 1), aux2);
            }
            else
            {
                inserirPosicao(L, i*2, aux2);
            }
            aux2 = temp;
        }
    }
}
*/
