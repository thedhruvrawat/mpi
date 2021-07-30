#include <mpi.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main (int argc, char **argv) {
  MPI_Init(&argc, &argv);
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  int local;
  local = atoi(argv[1]);
  int other;
  if(rank=0) {
    MPI_Send(&local, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(&other, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    cout<<local+other<<"\n";
  } else {
    MPI_Recv(&other, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Send(&local, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
    cout<<local*other<<"\n";
  }
  MPI_Finalize();
  return 0;
}
