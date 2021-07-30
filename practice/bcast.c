#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
  int size, rank;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  int buf[5];
  if(rank==0) {
    for(int i=0; i<5; i++) buf[i]=i*i;
    for(int id=1; id<size; id++) MPI_Send(buf, 5, MPI_INT, id, 0, MPI_COMM_WORLD);
  } else {
    MPI_Recv(buf, 5, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
  printf("Proc #%d: Buffer = ", rank);
  for(int i=0; i<5; i++) printf("%d ", buf[i]);
  printf("\n");

  MPI_Finalize();
  return 0;
}
