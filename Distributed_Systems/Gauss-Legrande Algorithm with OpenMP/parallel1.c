#include <omp.h>
#include <stdio.h>
#define N 100000000

main()
{

int i, n, n1;
float a[N], b[N], c[N], d[N];

/*Some initializations */

for(i = 0; i < N; i++)
{
	a[i] = b[i] = c[i] = i*1.0;
}
n = N;

omp_set_num_threads(2);

	#pragma omp parallel shared (a,b,c,n) private(i)
	{
		
		#pragma omp sections nowait
		{
			#pragma omp section
			{
				for(i=0; i < n/2; i++)
					d[i] = a[i] + b[i] + c[i];
			}
			#pragma omp section
			{
				for(i=n/2; i < n; i++)
					d[i] = a[i] + b[i] + c[i];
			}
			/* end of sections */
		}
		n1 = omp_get_num_threads();
		printf("Number of THRDS: %d\n", n1);
		/* end of parallel section */
	}
}
