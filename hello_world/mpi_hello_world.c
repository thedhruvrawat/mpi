#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {
   int size, rank;
   int res;
   
   //Initializing MPI environment
   res = MPI_Init(&argc, &argv);
   if(res != MPI_SUCCESS) {
     fprintf(stderr, "MPI_Init failed\n");
   }

   //Get the number of processes
   res = MPI_Comm_size(MPI_COMM_WORLD, &size);
   if(res != MPI_SUCCESS) {
     fprintf(stderr, "MPI_Comm_size failed\n");
     exit(0);
   }

   //Get the process rank
   res = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   if(res != MPI_SUCCESS) {
     fprintf(stderr, "MPI_Comm_rank failed\n");
     exit(0);
   }

   //Get the processor name
   char processor_name[MPI_MAX_PROCESSOR_NAME];
   int name_len;
   MPI_Get_processor_name(processor_name, &name_len);

   fprintf(stdout, "Hello world, this is %s, rank %d out of %d processors\n", processor_name, rank, size);

   //Finalizing MPI Environment
   res = MPI_Finalize();
   if(res != MPI_SUCCESS) {
     fprintf(stderr, "MPI_Finalize failed\n");
     exit(0);
   }
}
