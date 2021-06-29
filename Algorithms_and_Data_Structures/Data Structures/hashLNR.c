#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//#define tam 10 - ou definir na main

//TABELA HASH COM TRATAMENDO DE COLISÕES POR TESTE LINEAR

typedef struct celula  
{
    	int conteudo;
    	//char nome[100];
    	//long RA;
}celula;

int HASH(long conteudo, int tam)
{
	return conteudo % tam;
}

int REhash(int hash_conteudo, int tam)
{
	return (hash_conteudo + 1) % tam;
}


void insere_tabela(celula *tabela_hash, int tam, int conteudo)
{	

	int r = HASH(conteudo, tam);
	int qtd = 0;

	celula *aux = (celula*)malloc(sizeof(celula));

	aux->conteudo = conteudo;

	while (tabela_hash[r].conteudo != -1  && qtd < tam)
	{
		r = REhash(r,tam);
		qtd++;
	}
	if (qtd < tam) 
	{
		tabela_hash[r].conteudo = aux->conteudo;

		//strcpy(tabela_hash[r].nome, aux->nome); 	//em caso de strings					//para strings
	}
}

void imprime_hash(celula* tabela_hash, int tam)
{
	int i=0;

	for (int i = 0; i < tam; i++)
	{
		printf("\nTab[%d]: %d\n", i, tabela_hash[i].conteudo);
	}

	printf("\n");
}

int main(void)
{
	int tam, conteudo, i=0;

	printf("\nEntre com a quantidade de linhas da tabela = ");   
    scanf("%d",&tam);  
	
	celula* tabela_hash = (celula*)malloc(tam*sizeof(celula));

	for (i = 0; i < tam; i++)
	{
		tabela_hash[i].conteudo = -1;
	}

	for(i = 0;i < tam; i++)               
    { 
    		
    		printf("\nEntre com o valor da chave a ser inserida = "); 
        	scanf("%d",&conteudo); 
		
			insere_tabela(tabela_hash, tam, conteudo); 

    }

    imprime_hash(tabela_hash,tam);

	return 0;
}
