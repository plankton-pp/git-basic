#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int semiprime(int);
int main(int argc, char** argv){
	unsigned long long limit;
	unsigned long long count = 0;
	unsigned long long sum = 0;
	int rank,ntasks;
	double starttime, endtime;
	//Recv parametre
	if(argc!=2) {
	 //printf("%s <LIMIT>\n", argv[0]);
	}
	limit = atoi(argv[1]);
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD,&ntasks);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	starttime = MPI_Wtime();
	int i;
	for (i = 2; i < limit; i+=ntasks){
			int num = i;
			int round = i;
			for(int j=0;j<ntasks;j++){
				if(rank==j){
					if(round == num && rank==0){
						//MPI_Send(&count,1,MPI_UNSIGNED_LONG_LONG,rank+1,101,MPI_COMM_WORLD);
					}
						//MPI_Recv(&count,1,MPI_UNSIGNED_LONG_LONG,ntasks-1,101,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
						if (semiprime(num)){
							count+=1;
							//printf("Rank:%d | Count: %llu | %d \n",rank,count,num);
						}
						//MPI_Send(&count,1,MPI_UNSIGNED_LONG_LONG,rank+1,101,MPI_COMM_WORLD);
				}/*else if(rank<ntasks-1){
						//MPI_Recv(&count,1,MPI_UNSIGNED_LONG_LONG,rank-1,101,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
						if (semiprime(num)){
							count+=1;
						}
						//MPI_Send(&count,1,MPI_UNSIGNED_LONG_LONG,rank+1,101,MPI_COMM_WORLD);
				}else{
						//MPI_Recv(&count,1,MPI_UNSIGNED_LONG_LONG,rank-1,101,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
						if (semiprime(num)){
							count+=1;
						}
						//MPI_Send(&count,1,MPI_UNSIGNED_LONG_LONG,0,101,MPI_COMM_WORLD);
				}*/
				
				num++;
			}
			MPI_Reduce(&count,&sum,1,MPI_UNSIGNED_LONG_LONG,MPI_SUM,0,MPI_COMM_WORLD);
	}
	putchar('\n');
	endtime = MPI_Wtime();
	if(rank==0)
	 	printf("Deadly number of %llu is %llu (Elapsed time %.2f sec)\n",limit, sum, endtime-starttime);
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
