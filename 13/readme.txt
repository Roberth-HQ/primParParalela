mpicc -o mpi_vector mpi_vector.c
mpirun -np 3 ./mpi_vector
mpirun --oversubscribe -np 3 ./trece
