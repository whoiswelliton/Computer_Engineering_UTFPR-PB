#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

//#define num1 1000
//#define num2 982

int main(int argc, char* argv[])
{
	
	long num1 = 100000000000;
	long num2 = 911111111122;
	
	int nthreads, tid, tid2, mdc, mmc, n1, n2;
	
	omp_set_num_threads(1);
	
	#pragma omp parallel //num_threads(2)
	{
		
		if(tid == 0)
		{
			mdc = MDC(num1, num2);
			//mmc = MMC(num1, num2);
		}

		n2 = omp_get_num_threads();
		printf("Number of THR2: %d\n", n2);
	}
	
	printf("Maior Divisor Comum = %d\n",mdc);
	printf("Minimo Múltiplo Comum = %d\n",mmc);
}

int MDC(int num1, int num2)
{
	if(num2 == 0)
	{
		return num1;
	}
	else
	{
		return MDC(num2, num1 % num2);
	}
}
/*int MMC(int num1, int num2)
{
	//int i, j, aux = 0;
	return ((num1/MDC(num1, num2))*num2);	
}*/
