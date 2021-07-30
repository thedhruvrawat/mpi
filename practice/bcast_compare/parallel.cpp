
void play_parallel() {



  MPI_Barrier(MPI_COMM_WORLD);
  // Starting the chronometer
  double time = -MPI_Wtime(); // This command helps us measure time. We will see more about it later on !


    if (rank == 0) {
    buffer = new double[n_elements];
    
      // Initialising buffer :
    for (int i=0; i < n_elements; ++i)
        buffer[i] = (pow(-1, i))*i ;
  }

  // 1- Broadcast the value n_elements to all processes
  // [...]
  MPI_Bcast(&n_elements, 1, MPI_INT, 0, MPI_COMM_WORLD);


  // Here we create the buffers for the non-root processes now that
  // we have n_elements
  if (rank != 0)
    buffer = new double[n_elements];

  // 2- Broadcast the buffer to every process
  //    NOTE : The type here should be MPI_DOUBLE not MPI_FLOAT !
  // [...]
  MPI_Bcast(buffer, n_elements, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  

  // 3- Compute the sum depending on the rank
  double sum = 0.0;
  // [...]
  if(rank == 1) {
    for (int i=0; i < n_elements; ++i)
        if(buffer[i]>0) sum += buffer[i];
  } else if(rank==2) {
    for (int i=0; i < n_elements; ++i)
        if(buffer[i]<0) sum += buffer[i];
  } else {
    for (int i=0; i < n_elements; ++i)
        sum += buffer[i];
  }
  
  // Stopping the chronometer
  time += MPI_Wtime();

  // This line gives us the maximum time elapsed on each process.
  // We will see about reduction later on !
  double final_time;
  MPI_Reduce(&time, &final_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
  
  if (rank == 0)
    std::cout << "Total time for parallel scenario : " << final_time << "s" << std::endl;
}
