nproc
mpicc -o nom nom.c
mpirun -np 3 ./nom
mpirun --oversubscribe -np 3 ./once
