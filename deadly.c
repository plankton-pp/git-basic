#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int semiprime(int);
int main(int argc, char** argv){
	unsigned long long limit;
	unsigned long long count = 0;
	int rank,ntasks;
	double starttime, endtime;
	//Recv parametre
	if(argc!=2) {
	 printf("%s <LIMIT>\n", argv[0]);
	}
	limit = atoi(argv[1]);
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD,&ntasks);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	starttime = MPI_Wtime();
	int i;
	for (i = 2; i < limit; i++){
		if (semiprime(i)){
			count+=1;
		}
	}
	putchar('\n');
 
	 
	 endtime = MPI_Wtime();
	 if(rank==0)
	 	printf("Deadly number of %llu is %llu (Elapsed time %.2f sec)\n",limit, count, endtime-starttime);
	 MPI_Finalize();
	return 0;
}
int semiprime(int n)
{
	int p, f = 0;
	for (p = 2; f < 2 && p*p <= n; p++)
		while (0 == n % p)
			n /= p, f++;
 
	return f + (n > 1) == 2;
}