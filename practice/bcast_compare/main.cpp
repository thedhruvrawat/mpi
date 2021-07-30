#include <iostream>
#include <unistd.h>
#include <mpi.h>
#include <bits/stdc++.h>
#include <iomanip>

int rank, size;
int n_elements = 10000000;
double *buffer;


#include "procedure.cpp"
#include "parallel.cpp"

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  MPI_Barrier(MPI_COMM_WORLD);

  if (rank == 0)
    std::cout << "========= Running procedure scenario =========" << std::endl;
  play_procedure();

  MPI_Barrier(MPI_COMM_WORLD);

  if (rank == 0)
    std::cout << "======= Running parallel scenario =======" << std::endl;
  play_parallel();

  MPI_Finalize();
  
  return 0;
}
