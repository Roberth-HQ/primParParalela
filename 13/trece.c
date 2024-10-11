#include <stdio.h>
#include <string.h>
#include <mpi.h>

#define MAX_STR_LEN 100
#define VECTOR_SIZE 10

int main(int argc, char** argv) {
    int rank, size;
    char data[VECTOR_SIZE][MAX_STR_LEN]; // Vector de cadenas
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Proceso 0 inicializa el vector de cadenas
        for (int i = 0; i < VECTOR_SIZE; i++) {
            snprintf(data[i], MAX_STR_LEN, "Elemento %d", i);
        }

        // Enviar datos a los procesos 1 y 2
        for (int i = 1; i < size; i++) {
            MPI_Send(data, VECTOR_SIZE * MAX_STR_LEN, MPI_CHAR, i, 0, MPI_COMM_WORLD);
        }
    } else {
        // Procesos 1 y 2 reciben el vector de cadenas
        MPI_Recv(data, VECTOR_SIZE * MAX_STR_LEN, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Desplegar posiciones pares o impares
        printf("Proceso %d: ", rank);
        for (int i = (rank - 1); i < VECTOR_SIZE; i += 2) {
            printf("%s ", data[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
