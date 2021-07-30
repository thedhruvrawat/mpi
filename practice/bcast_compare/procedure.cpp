
void play_procedure() {

    MPI_Barrier(MPI_COMM_WORLD);
    if(rank==0) {
    // Starting the chronometer
    double t1 = MPI_Wtime(); // This command helps us measure time. We will see more about it later on !

    
    buffer = new double[n_elements];
    
      // Initialising buffer :
    for (int i=0; i < n_elements; ++i)
        buffer[i] = (pow(-1, i))*i ;
    

  
  // 3- Compute the sum depending on the rank
    double sum = 0.0;
  // [...]
    for (int i=0; i < n_elements; ++i)
        if(buffer[i]>0) sum += buffer[i];
    sum = 0.0;
    for (int i=0; i < n_elements; ++i)
        if(buffer[i]<0) sum += buffer[i];
    sum = 0.0;
    for (int i=0; i < n_elements; ++i)
        sum += buffer[i];
  
  // Stopping the chronometer
    double t2 = MPI_Wtime();

    // This line gives us the maximum time elapsed on each process.
    // We will see about reduction later on !
    double final_time = t2-t1;
    std::cout << "Total time for procedure scenario : " << final_time << "s" << std::endl;
    }
}
