#include <mpi.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
  int rank, size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  cout<<"Hello world from process #"<<rank<<endl;  
  int MPI_Finalize();
  return 0;  
}
