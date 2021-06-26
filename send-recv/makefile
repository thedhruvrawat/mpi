EXECS=send_recv ping-pong ring
MPICC?=mpicc

all: ${EXECS}

send_recv: send_recv.c
	${MPICC} -o send_recv send_recv.c

ping-pong: ping-pong.c
	${MPICC} -o ping-pong ping-pong.c

ring: ring.c
	${MPICC} -o ring ring.c

clean:
	rm ${EXECS}
