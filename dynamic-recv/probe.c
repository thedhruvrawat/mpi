#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
  int rank, size;
  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if(size!=2) {
    fprintf(stderr, "Must use two processes\n");
    MPI_Abort(MPI_COMM_WORLD,1);
  }

  int num_count;
  if(rank == 0) {
    const int MAX_NUM=100;
    int num[MAX_NUM];
    srand(time(NULL));
    num_count = (rand()/(float)RAND_MAX)*MAX_NUM;
    MPI_Send(num, num_count, MPI_INT, 1, 0, MPI_COMM_WORLD);
    printf("0 sent %d numbers to 1\n", num_count);
  } else if (rank==1) {
    MPI_Status status;
    MPI_Probe(0,0,MPI_COMM_WORLD, &status);
    MPI_Get_count(&status, MPI_INT, &num_count);
    int* num_buf = (int*)malloc(sizeof(int)*num_count);
    MPI_Recv(num_buf, num_count, MPI_INT, 0,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("1 dynamically received %d numbers from 0.\n", num_count);
    free(num_buf);
  }
  MPI_Finalize();
}
