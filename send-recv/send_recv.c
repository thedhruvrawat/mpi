#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  MPI_Init(NULL, NULL);
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if(size<2) {
    fprintf(stderr, "Size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int num;
  if(rank == 0) {
   // If rank 0, set num to -1 and send to process 1
   num=-1;
   MPI_Send(&num,1,MPI_INT,1,0,MPI_COMM_WORLD);
  } else if(rank == 1) {
    MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from process 0\n", num);
  }
  MPI_Finalize();
} 
