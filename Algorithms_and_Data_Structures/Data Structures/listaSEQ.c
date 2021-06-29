#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100  //como é estática eu defino o tamanho dela uma vez só

//LISTA SEQUENCIAL ALOCADA ESTATICAMENTE

typedef struct celula{			
	int conteudo;
	//char info[20];
}celula;

typedef struct ListaSEQ{
	int cont;
	celula dados[MAX];
}ListaSEQ;


ListaSEQ *cria_lista ()
{
	ListaSEQ *l;
	l = (ListaSEQ*) malloc(sizeof(ListaSEQ));
	if(l != NULL)
	{
		l->cont = 0;
	}
	return l;
}

int tamanho_lista(ListaSEQ *l)
{
	if(l == NULL)
	{
		return -1;
	}
	else
	{
		return (l->cont);
	}
}

int lista_cheia (ListaSEQ *l)
{
	if(l == NULL)
	{
		return -1;
	}
	return(l->cont == MAX);       //lista cheia
}

int lista_vazia (ListaSEQ *l)
{
	if(l == NULL)
	{
		return -1;
	}
	return (l->cont == 0);
}

int insere_inicio (ListaSEQ *l, celula A)
{
	int i;

	if(l == NULL)
	{
		return 0;
	}
	if(lista_cheia(l))
	{
		return 0;
	}
	for(i=l->cont-1; i>=0; i--)
	{	
		l->dados[i+1] = l->dados[i];
	}

	l->dados[0] = A;
	l->cont++;
	return 1;	
}

int insere_final(ListaSEQ *l, celula A)
{
	if(l == NULL)
	{
		return 0;
	}
	if(lista_cheia(l))
	{
		return 0;
	}

	l->dados[l->cont] = A;
	l->cont++;
	return 1;
}


int insere_ordenado (ListaSEQ *l, celula A)
{
	if(l == NULL)
	{
		return 0;
	}
	if(lista_cheia(l))
	{
		return 0;
	}

	int k,i=0;

	while(i < l->cont && l->dados[i].conteudo < A.conteudo)
	{
		i++;
	}
	for(k = l->cont-1;k >= i; k--)
	{
		l->dados[k+1] = l->dados[k];
	}

	l->dados[i] = A;
	l->cont++;
	return 1;
}

int remove_inicio (ListaSEQ *l)
{
	if(l == NULL)
	{
		return 0;
	}
	if(lista_vazia(l))
	{
		return 0;
	}

	int k=0;

	for(k = 0; k < l->cont-1; k++)
	{
		l->dados[k] = l->dados[k+1];
	}

	l->cont--;
	return 1;
}

int remove_final (ListaSEQ *l)
{
	if(l == NULL)
	{
		return 0;
	}
	if(lista_vazia(l))
	{
		return 0;
	}

	l->cont--;
	return 1;
}

int remove_elemento_especifico (ListaSEQ *l, int conteudo)
{
	if(l == NULL)
	{
		return 0;
	}
	if(l->cont == 0)
	{
		return 0;
	}

	int i=0;

	while(i < l->cont && l->dados[i].conteudo != conteudo)
	{
		i++;
	}
	if (i == l->cont)    //elemento não encontrado
	{
		return 0;
	}

	l->cont--;
	l->dados[i] = l->dados[l->cont];
	return 1;
}

int busca_posicao (ListaSEQ *l, int pos)
{
	if(l == NULL || pos < 0 || pos > l->cont)
	{
		return -1;
	}

	return l->dados[pos].conteudo;
}

int busca_elemento_conteudo (ListaSEQ *l, int conteudo)
{
	if(l == NULL)
	{
		return -1;
	}

	int i=0;

	while(i< l->cont)
	{
		if(l->dados[i].conteudo == conteudo)
		{
			return i;
		}
		i++;
	}
	if(i == l->cont)  //elemento não encontrado
	{
		return -1;
	}
	
}


int BUSCA_BINARIA (ListaSEQ *l, int valor, int tam)  	
{
	int e, m, r;                              
	e = 0;                                        		 //LEFT
   	r = tam-1;                               		 //RIGHT
                       
   	while (e <= r) 
	{                				     
		m = (e + r)/2;					 //MIDDLE 
	                       
     	if (valor == l->dados[m].conteudo) 
		{
			return(m);
		}
		else if (valor > l->dados[m].conteudo)
		{
			e = m + 1;
		}               
      	else
		{
			r = m - 1;
		}                        
   	}                                  
   return -1;                                
}  

void QUICK_SORT_CRESCENTE(ListaSEQ *l, int inicio, int fim)
{
	int i, j, aux, meio;
	
	i = inicio;
	j = fim;
	meio = (int)((inicio + fim)/2);
	
	if(i < j)
	{
		while(l->dados[i].conteudo < l->dados[meio].conteudo)
		{
			i++;
		}
		while(l->dados[j].conteudo  > l->dados[meio].conteudo)
		{
			j--;
		}
		if(i <= j)
		{
			aux = l->dados[i].conteudo;
			l->dados[i].conteudo = l->dados[j].conteudo;
			l->dados[j].conteudo = aux;
			i++; 
			j--;
		}
	}
	if(j > inicio) 
	{
		QUICK_SORT_CRESCENTE(l, inicio, j);
	}
	if(i < fim) 
	{
		QUICK_SORT_CRESCENTE(l, i, fim);
	}
}

void QUICK_SORT_DECRESCENTE(ListaSEQ *l, int inicio, int fim)   
{
  	int i, j, aux, m;

	i = inicio;
	j = fim;
	m = (int)((inicio + fim)/2);
	 
	if(j > i)
	{
	    while(l->dados[i].conteudo > l->dados[m].conteudo)
	    {
	       i++;
	    }
	    while(l->dados[j].conteudo < l->dados[m].conteudo)
	    {
			j--;
	    }
	    if(j <= i)  
	    {
		    aux = l->dados[i].conteudo;
		   	l->dados[i].conteudo = l->dados[j].conteudo;
			l->dados[j].conteudo = aux;
			i++;
			j--;
	    }
	}
	  
	if(j > inicio) 
	{
	    QUICK_SORT_DECRESCENTE(l, inicio, j);
	}
	if(i < fim) 
	{
	    QUICK_SORT_DECRESCENTE(l, i, fim);
	}
}

int elementos_em_comum (ListaSEQ *l1, ListaSEQ *l2, int t1, int t2)
{
	int i=0,j=0;

	printf("\n*Elementos em comum entre l1 e l2\n");
	for(i =0 ; i < t1; i++)
	{
		for(j = 0; j < t2; j++)
		{
			if(l1->dados[i].conteudo == l2->dados[j].conteudo)
			{
				printf(" %d ",l1->dados[i].conteudo);
			}
		}
	}
}

void imprime_lista (ListaSEQ *l)  		
{
	int i=0;

	if (l->cont != 0)
	{
		for (i = 0; i < l->cont; i++)
		{
			printf(" %d ",l->dados[i].conteudo);
		}
	}

}

/*
//ordenação por chave
void SelectionSort(lista *L)
{
    int i, j;
    elem aux;
    for(i = 1; i <= L->nElem - 1; i++)
    {
        for(j = i + 1; j <= L->nElem; j++)
        {
            if(L->A[i].chave > L->A[j].chave)
            {
                aux = L->A[i];
                L->A[i] = L->A[j];
                L->A[j] = aux;
            }
        }
    }
}
*/
/*
//insere por chave de forma ordenada.
int inserirOrdenado(lista *L, elem *x, int chave)
{
    if(L->nElem == 0)
    {
        Inserir(L, x, 1);
        return 1;
    }
    else
    {
        int atual;
        if(L->A[L->nElem].chave < chave)
        {
            Inserir(L, x, (L->nElem + 1));
            return 1;
        }
        else
        {
            for(atual=L->nElem; atual >= 1; atual--)
            {
                L->A[atual+1] = L->A[atual];
                if(L->A[atual].chave > chave && L->A[atual-1].chave < chave)
                {
                    L->A[atual]= *x;
                    L->nElem++;
                    return 1;
                }
            }
        }

    }
    return -1;
}
*/
/*

//imprime igual por chave.
void imprimirIguais2(lista *L1, lista *L2)
{
    if(L1->nElem == 0 && L2->nElem == 0)
    {
        printf("\nNao ha elementos para imprimir.\n");
    }
    int atual;
    int atual2;
    for(atual = 1; atual <= L1->nElem; atual++)
    {
        for(atual2 = 1; atual2 <= L2->nElem; atual2++)
        {
            if(L1->A[atual].chave == L2->A[atual2].chave)
            {
                printf("\nElemento:%d \tPosicao L1:%d \tPosicao L2:%d\n", L1->A[atual].chave, atual, atual2);
            }
        }
    }
}
*/
/*
//questão 6.
void removerDuplicados(lista *L)
{
    if(L->nElem == 0)
    {
        printf("\nNao ha elementos para remover.\n");
    }
    int atual;
    int atual2;
    for(atual = 1; atual <= L->nElem; atual++)
    {
        for(atual2 = atual + 1; atual2 <= L->nElem; atual2++)
        {
            if(L->A[atual].chave == L->A[atual2].chave)
            {
                Remover(L, atual2);
            }
        }
    }
}
*/

/*
int trocarPosicao(lista *L, int p, int q)
{
    elem aux;
    int atual;
    if(p < 1 || p > L->nElem || q < 1 || q > L->nElem)
    {
        return -1;
    }
    else
    {
        aux = L->A[p];
        //Remover(L, p);
        //Inserir(L, &aux, q);
        //return 1;
        if(q > p)
        {
            for(atual = p; atual < q; atual++)
            {
                L->A[atual] = L->A[atual + 1];
            }
            L->A[atual] = aux;
            return 1;
        }
        else if(q < p)
        {
            for(atual = p; atual > q; atual--)
            {
                L->A[atual] = L->A[atual - 1];
            }
            L->A[atual] = aux;
            return 1;
        }
    }
}
*/
void apaga_lista (ListaSEQ *l)
{
	free(l);
}

int main (void)
{
	int i, aux1, aux2, aux3;
	ListaSEQ *l,*l1,*l2;
	celula A,B,C;

	l = cria_lista ();
	l1 = cria_lista ();
	l2 = cria_lista ();

	printf("\n-> LISTA SEQUENCIAL ESTATICA:\n");
	
	for (i = 0; i < 10; ++i)
	{
		A.conteudo = i;
		insere_inicio(l, A);

		//A.conteudo = rand()%100;
		//insere_ordenado (l, A);
	}

	A.conteudo = 15;

	insere_final(l, A);

	imprime_lista (l);

	printf("\n\n-> APOS REMOCOES:\n");

	remove_inicio (l);

	remove_final (l);

	remove_elemento_especifico (l, 5);

	imprime_lista (l);

	printf("\n\n-> APOS BUSCAS:\n");

	aux1 = busca_posicao (l, 3);

	if(aux1 != -1)
	{
		printf("\n*Conteudo Encontrado na Posicao: %d \n",aux1);
	}
	else
	{
		printf("\n*Posicao fora do intervalo da lista\n");
	}
	

	aux2 = busca_elemento_conteudo (l, 3);
	
	if(aux2 != -1)
	{
		printf("\n*Posicao do Conteudo Encontrado: %d \n",aux2);

	}
	else
	{
		printf("\n*Conteudo nao Encontrado na Lista\n");
	}

	QUICK_SORT_CRESCENTE(l, 0, l->cont-1);
	//QUICK_SORT_DECRESCENTE (l, 0, l->cont-1);

	printf("\n-> LISTA ORDENADA:\n");

	imprime_lista (l);

	aux3 = BUSCA_BINARIA (l, 3, l->cont);

	if(aux3 != -1)
	{
		printf("\n\n*Esta na posicao: %d \n",aux3);
	}
	else
	{
		printf("\n\n*Conteudo nao Encontrado na Lista\n");
	}
	
	i=0;
	A.conteudo = 0;
	B.conteudo = 0;
	for (i = 0; i < 10; i++)
	{
		A.conteudo = rand()%10;
		B.conteudo = rand()%10;
		insere_inicio(l1, A);
		insere_inicio(l2, B);
	}

	imprime_lista (l1);
	printf("\n\n");
	imprime_lista (l2);
	printf("\n\n");

	elementos_em_comum (l1, l2, l1->cont,l2->cont);
	printf("\n\n");

	apaga_lista (l);

	return 0;
}
