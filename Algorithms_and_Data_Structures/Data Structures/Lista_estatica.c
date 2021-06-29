/*Uma estrutura do tipo "Lista" é uma sequencia de elementos do mesmo tipo.
Seus elementos possuem estrutura interna abstraida, ou seja, sua complexidade
é arbitraria e não afeta o funcionamento do programa
Ou seja, o funcionamento é sempre o mesmo
Lista possui N (N>=0) Elementos, se N =0 a lista está vazia
Operações para implementar:
- Cria
- Insere
- Remove(por chave, por posição)
- Acessa
Lista estatica:
- O espaço de memória é alocado no momento da alocação
- Exige definição do numero máximo de elementos da "Lista"
- Acesso sequencial: elementos consecutivos na memória, ou seja, um vetor

Vantagens do uso:
- Acesso rápido e direto aos elementos(indice)
- Tempo constante para acessar um elemento
- Facilidade em modificar informações
Desvantagens do uso:
- Definição prévia do uso do tamanho do vetor.
- Dificuldade para inserir e remover um elemento entre outros dois: é necessario deslocação

Quando usar?
- Listas pequenas
- Inserção/remoção apenas no final da lista
- Tamanho max bem definido
- A busca é a operação mais frequente
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100
typedef struct
{
    int chave;
    char info[20];

}elem;

typedef struct
{
    elem A[Max+1];
    int nElem;
}lista;

void definir (lista *L)
{
    L->nElem = 0;
    L->A[0].chave = 0;
    strcpy(L->A[0].info,"\0");//copia a string original para a destino
}

int tamanho(lista *L)
{
    return L->nElem;
}
int Inserir(lista *L, elem *x, int p)
{
    int atual;
    if(L->nElem == Max)
    {
        return -1;
    }
    else if(p>tamanho(L)+1||p<1)
    {
        return -1;
    }
    else
    {
        for(atual=L->nElem; atual >= p; atual--)
        {
            L->A[atual+1] = L->A[atual];
        }
        L->A[p]= *x;
        L->nElem++;
        return 1;
    }
}

int Remover(lista *L, int p)
{
    int atual;
    if(p>L->nElem || p<1 ||L->nElem==0)
    {
        return -1;
    }
    else
    {
        for(atual=p+1; atual <= L->nElem;atual++)
        {
            L->A[atual-1]= L->A[atual];
        }
        L->nElem--;
    }
    return 1;
}

int Busca(lista *L, int chave)
{
    if(L->nElem == 0)
    {
        return -1;
    }
    else
    {
        int atual;
        for(atual = 1; atual <= L->nElem; atual++)
        {
            if(L->A[atual].chave == chave)
            {
                printf("\nEncontrado - ");
                return(atual);
            }
        }
        return -1;
    }
}

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


elem* Obter (int P, lista *L)
{
    if (P > L->nElem || P<1 || L->nElem == 0)
    {
        return(NULL);
    }
    else
    {
        return(&L->A[P]);
    }
}

void imprimir(lista *L)
{
    int atual;
    for(atual = 1; atual <= L->nElem; atual++)
    {
        printf("Chave: %d - Info: %s\n", L->A[atual].chave, L->A[atual].info);
    }
}

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
int main (void)
{
    lista L;
    lista L2;
    definir(&L);
    definir(&L2);

    elem um;
    um.chave = 11;
    strcpy(um.info, "aquaman");
    Inserir(&L, &um, 1);

    elem dois;
    dois.chave = 7;
    strcpy(dois.info, "coringa");
    Inserir(&L,&dois, 2);

    elem tres;
    tres.chave = 21;
    strcpy(tres.info, "batman");
    Inserir(&L,&tres, 3);

    //Remover(&L, 2);

    //teste questão 3
    /*int res;
    res = Busca(&L, 13);
    printf("\tPosicao: %d", res);*/

    //teste questão 4
    /*SelectionSort(&L);
    printf("\n");
    imprimir(&L);*/

    //teste questão 5
    elem quatro;
    quatro.chave = 29;
    strcpy(quatro.info, "teste1");
    inserirOrdenado(&L, &quatro, quatro.chave);
    elem cinco;
    cinco.chave = 5;
    strcpy(cinco.info, "teste2");
    inserirOrdenado(&L, &cinco, cinco.chave);

    printf("\n");
    imprimir(&L);

    //teste questão 5
    /*elemento X2;
    X2.chave = 10;
    strcpy(X2.info, "Pele");
    Inserir(&L2, &X2, 1);

    elemento y2;
    y2.chave = 13;
    strcpy(y2.info, "fer");
    Inserir(&L2,&y2, 2);

    elemento z2;
    z2.chave = 15;
    strcpy(z2.info, "kaka");
    Inserir(&L2,&z2, 3);

    printf("\n");
    imprimir(&L2);

    imprimirIguais2(&L, &L2); */

    /*//teste questão 6
    removerDuplicados(&L);
    printf("\n");
    imprimir(&L);*/

    //teste exericio extra
    int res;
    res = trocarPosicao(&L, 1, 5);
    printf("\n");
    imprimir(&L);


}

