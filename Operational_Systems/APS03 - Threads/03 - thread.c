#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

//gcc Trabalho3.c -lpthread -lm -o c
// times ./Trabalho3

#define BILLION 1000000000

double TOTAL[1024];  //vetor com uma estimativa do número total de threads que podem ser armazenadas
int SIZE = 0; //tamanho de cada intervalo dependendo do número de threads

void *gregory_series (void *i)
{
      int k, j = (int)i;
      TOTAL[j] = 0;

      for(k = j*SIZE; k < ((j+1)*SIZE); k++)
      {
      	TOTAL[j] = TOTAL[j] + (pow(-1.0,k))/(2.0*k + 1.0); //Forma geral da série
      }
}

int main(int argc, char *argv[])
{
	int i = 0;
	int num = atoi(argv[1]); //qtd de threads lidas do usuário
	double resultado = 0; 
	
	SIZE = BILLION/num; //tamanho do intervalo
	pthread_t thread[num]; //declarando um vetor do tipo thread do tamanho do número informado
	
	for(i = 0; i < num; i++)
	{
		//criando N threads
		pthread_create(&thread[i], NULL, gregory_series, (void*)i); 
	}


	for(i = 0; i < num; i++)
	{
		pthread_join(thread[i], NULL);
		resultado = resultado + TOTAL[i];
	}

	printf("Resultado: %.20f\n",resultado*4);
}
