## Sending and Receiving in MPI

Intended to work with installations of MPICH2. To check, run `mpiexec --version`

### Intructions to run locally
- Clone the repo locally and then move into current folder

```bash
$ git clone https://github.com/thedhruvrawat/mpi.git
$ cd send-recv
```

- Run `make` command to build the C output files `send_recv`, `ping-pong` and `ring`.

```bash
$ make
```

- Run the following command to view the output. In place of `NUM_OF_PROCESSES` enter the number of processes you want to spawn and either `send_recv`, `ping-pong` or `ring` in place of `OUTPUT_FILE`

```bash
$ mpiexec -n NUM_OF_PROCESSES ./OUTPUT_FILE
```

### Output Format
The output should look something like this

- ### send_recv
Do ensure that the no. of processes is atleast greater than 1.
```bash
$ mpiexec -n 2 ./send_recv
```
```bash
Process 1 received number -1 from process 0
```

- ### ping-pong
Do ensure that the no. of processes is 2.
```bash
$ mpiexec -n 2 ./ping-pong
```
```bash
0 sent and incremented ping_pong_count 1 to 1
1 received ping_pong_count 1 from 0
0 received ping_pong_count 2 from 1
0 sent and incremented ping_pong_count 3 to 1
1 sent and incremented ping_pong_count 2 to 0
1 received ping_pong_count 3 from 0
1 sent and incremented ping_pong_count 4 to 0
0 received ping_pong_count 4 from 1
0 sent and incremented ping_pong_count 5 to 1
0 received ping_pong_count 6 from 1
0 sent and incremented ping_pong_count 7 to 1
1 received ping_pong_count 5 from 0
1 sent and incremented ping_pong_count 6 to 0
1 received ping_pong_count 7 from 0
1 sent and incremented ping_pong_count 8 to 0
0 received ping_pong_count 8 from 1
0 sent and incremented ping_pong_count 9 to 1
0 received ping_pong_count 10 from 1
1 received ping_pong_count 9 from 0
1 sent and incremented ping_pong_count 10 to 0
```


- ### ring
Do ensure that the no. of processes is 2.
```bash
$ mpiexec -n 7 ./ring
```
```bash
Process 1 received token -1 from process 0
Process 2 received token -1 from process 1
Process 3 received token -1 from process 2
Process 4 received token -1 from process 3
Process 5 received token -1 from process 4
Process 6 received token -1 from process 5
Process 0 received token -1 from process 6
```

