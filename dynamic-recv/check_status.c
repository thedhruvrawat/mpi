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

  const int MAX_NUM=100;
  int num[MAX_NUM];
  int num_count;
  if(rank == 0) {
    srand(time(NULL));
    num_count = (rand()/(float)RAND_MAX)*MAX_NUM;
    MPI_Send(num, num_count, MPI_INT, 1, 0, MPI_COMM_WORLD);
    printf("0 sent %d numbers to 1\n", num_count);
  } else if (rank==1) {
    MPI_Status status;
    MPI_Recv(num, MAX_NUM, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    MPI_Get_count(&status, MPI_INT, &num_count);
    printf("1 received %d numbers from 0. Message source = %d, tag = %d\n", num_count, status.MPI_SOURCE, status.MPI_TAG);
  }
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
}
