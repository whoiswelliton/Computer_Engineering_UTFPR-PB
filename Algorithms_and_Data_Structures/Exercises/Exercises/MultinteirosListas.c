#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//construtores//
typedef struct _Item Item;
typedef struct _Lista Lista;


struct _Item
{
	int valor;
	Item* prox;
	Item* ant;
};


struct _Lista
{
	Item* inicio;
	Item* fim;
	int tamanho;
};

//Operacoes de lista//
Lista* novaLista()
{
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim	= NULL;
	l->tamanho = 0;

	return l;
}

Item* novoItem(int value)
{
	Item *item = (Item*) malloc(sizeof(Item));
	item->valor = value;
	item->prox  = NULL;
	item->ant  = NULL;
	return item;
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

// =============================================================================

//Inserir//

void inserirInicio(Lista* l, Item* novo)
{
	// Se lista vazia
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
	// Se lista vazia
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
Item* removerInicio(Lista* l)
{
assert(l->tamanho > 0);

Item* removed = NULL;

if (l->tamanho == 1)
{
 removed = l->inicio;
 l->inicio = NULL;
 l->fim = NULL;
} else {
 removed = l->inicio;
 l->inicio = removed->prox;
 
 l->inicio->ant = NULL;
}
l->tamanho--;

return removed;
}

void freeLista(Lista* l)
{
while (l->inicio != NULL)
 free(removerInicio(l));
}


// =============================================================================

//Funcoes do problema//

//nucleo de adicao//
int CalAdicao(int soma, Lista* result){
	int sobra = 0;
 
	if (soma < 10){
		inserirInicio(result, novoItem(soma));
	}
 
	else{
		sobra = soma/10;
		soma = soma%10;
		inserirInicio(result, novoItem(soma));
	}
	return sobra;
}

//nucleo de mult//
int CalMult(int mult, Lista* adicionar){
	int sobra = 0;
 
	if (mult < 10){
		inserirInicio(adicionar, novoItem(mult));
	}
 
	else {
		sobra = mult/10;
		mult = mult%10;
		inserirInicio(adicionar, novoItem(mult));
	}
	return sobra;
}

// add listas  para multiplicacao. Usar A = result, B =adicionar//
Lista* addListasMult(Lista* A, Lista* B){
	int sobra = 0, soma;
	Item *tmp1, *tmp2;
	Lista* resulttmp = novaLista();
	
	if ((A->tamanho) == 0 && (B->tamanho == 0))
		return NULL;

	if (A->tamanho == 0)
		return B;

	if (B->tamanho == 0)
		return A;

	tmp1 = A->fim;
	tmp2 = B->fim;
	
	//Anda as ultimas casas, e armazena as sobras para a proxima operacao enquanto uma das listas n chega no inicio//
	while ((tmp1 != A->inicio) && (tmp2 != B->inicio)){
		soma = (tmp1->valor + tmp2->valor) + sobra;
		sobra = 0;

	sobra = CalAdicao(soma,resulttmp);

		tmp1 = tmp1->ant;
		tmp2 = tmp2->ant;
	}

	//Faz a operacao quando pelo menos uma das listas chegou ao seu inicio//
	soma = (tmp1->valor + tmp2->valor) + sobra;
	sobra = 0;
 
	sobra = CalAdicao(soma, resulttmp);
 
	//O que sobrou//
	while (tmp1->ant != NULL){
		tmp1 = tmp1->ant;
		soma = (tmp1->valor + sobra);
		sobra = 0;
 
		sobra = CalAdicao(soma, resulttmp);
	}

	while (tmp2->ant != NULL){
		tmp2 = tmp2->ant;
		soma = (tmp2->valor + sobra);
		sobra = 0;

		sobra = CalAdicao(soma, resulttmp);
	}
 
	if (sobra != 0){
		inserirInicio(resulttmp, novoItem(sobra));
		sobra = 0;
	}
	
	freeLista(A);
	free(A);
 
	return resulttmp;
}

Lista* multListas2(Lista* A, Lista* B){
    Item *tmp1 = A->fim, *tmp2 = B->fim;
	int sobra = 0, mult, digito1 = 0, digito2 = 0, i;
 
	Lista* adicionar = novaLista();
	Lista* result = NULL;
	Lista* resulttmp = NULL;
	Lista* ultimocalc = NULL;
	
    while (tmp2){
        while (tmp1){
            mult = (tmp1->valor * tmp2->valor) + sobra;
            sobra = 0;

            sobra = CalMult(mult, adicionar);
            tmp1 = tmp1->ant;
			
			if (sobra != 0){
				inserirInicio(adicionar, novoItem(sobra));
				sobra = 0;
			}
			
			if (digito1 == 0){
				result = adicionar;
				adicionar = novaLista();
			}

            else{
				for (i=1; i<= digito1; i++){
					inserirFim(adicionar, novoItem(0));
				}
                resulttmp = addListasMult(result, adicionar);
				result = resulttmp;
				if (adicionar->tamanho != 0){
					freeLista(adicionar);
				}
            }
			digito1++;
        }
	
	if (B->tamanho == 1){
		return result;
	}
	if (digito2 > 0){
		for (i=1; i<= digito2; i++){
				inserirFim(result, novoItem(0));
			}
	}
	
	
	if (digito2 == 0){
		ultimocalc = result;
		result = novaLista();
	}
	
	else {
		ultimocalc = addListasMult(ultimocalc, result);
	}
	
	digito2++;
		
	digito1 = 0;
	tmp2 = tmp2->ant;
	tmp1 = A->fim;
    }
	return ultimocalc;
}

// =============================================================================

void CharParaLista(const char* Frase, Lista* Nova){
	int tmp, i, fim = strlen(Frase);
 
	for (i=0; i<fim; i++){
		tmp = Frase[i] - '0';
		inserirNaPosicao(Nova, novoItem(tmp), i);
	}
}

void printLista(Lista* l)
{
	if (l->inicio != NULL)
	{
		Item* curr = l->inicio;
		while(curr != l->fim)
		{
			fprintf(stdout, "%d", curr->valor);
			curr = curr->prox;
		}
		fprintf(stdout, "%d\n", curr->valor);
	}
}

int main()
{
	char* A = (char *)malloc(512000 * sizeof(char));
	char* B = (char *)malloc(512000 * sizeof(char));
	scanf("%s %s", A, B);

	Lista* Lista1 = novaLista();
	Lista* Lista2 = novaLista();

	CharParaLista(A, Lista1);
	CharParaLista(B, Lista2);

	Lista* Resultado = multListas2(Lista1, Lista2);
	printLista(Resultado);
 
	return 0;
}