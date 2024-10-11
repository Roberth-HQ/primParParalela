mpicc -o mpi_matrix_mult mpi_matrix_mult.c
mpirun -np 4 ./mpi_matrix_mult
mpirun --oversubscribe -np 4 ./mpi_matrix_mult
