## Hello World in MPI

Intended to work with installations of MPICH2. To check, run `mpiexec --version`

### Intructions to run locally
- Clone the repo locally and then move into current folder

```bash
$ git clone https://github.com/thedhruvrawat/mpi.git
$ cd hello_world
```

- Run `make` command to build the C output file `hello_world_mpi`

```bash
$ make
```

- Run the following command to view the output. In place of `NUM_OF_PROCESSES` enter the number of processes you want to spawn

```bash
$ mpiexec -n NUM_OF_PROCESSES ./hello_world_mpi
```

### Output Format
The output should look something like this

```bash
$ mpiexec -n 3 ./hello_world_mpi
```
```bash
Hello world, this is Dhruv, rank 0 out of 3
Hello world, this is Dhruv, rank 2 out of 3
Hello world, this is Dhruv, rank 1 out of 3
```

Note: `Dhruv` is the name of the processor

The output may rank in arbitrary order since there is no synchronization involved before printing