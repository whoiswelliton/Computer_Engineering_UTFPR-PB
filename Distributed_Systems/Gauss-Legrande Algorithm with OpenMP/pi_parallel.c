#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10000

//[PARALLEL]

//Algoritmo de Gauss-Legrande Iterativo para o Cálculo de PI

long double pi(int iterations)
{
	//inicializações
	double i;
	long double a = 1;
	long double b = sqrt(2)/2;
	long double t = 0.25;
	long double p = 1;
	long double a_next, b_next, t_next, aux; //constantes auxiliares	
	
	for(i = 0; i < iterations; i++)
	{
		//calcula as constantes da iteração 1
		a_next = (a + b)/2;
		b_next = sqrt(a * b);
		aux = a - a_next; //evita o uso de pow(a, 2)
		t_next = t - p * aux * aux;
		
		//atualização das variáveis
		p = 2*p;
		a = a_next;
		b = b_next;
		t = t_next;
	}
	
	aux = (a + b)/2; //evita o uso de pow(a, 2)
	return (aux * aux / t);
}

int main(int argc, char* argv[])
{
	int n, i=0;
	omp_set_num_threads(4);
	
	#pragma omp parallel
	{
		for (i = 0; i <= N; i++)
		{
			printf("i = %d: %1.80Lf\n",i, pi(i));
		}
		n = omp_get_num_threads();
		printf("Number of THRDS: %d\n", n);
	}
}
