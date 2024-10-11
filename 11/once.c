#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define VECTOR_SIZE 10 // Definición del tamaño del vector

int main(int argc, char **argv) {
    int rank, size;
    int vectorA[VECTOR_SIZE], vectorB[VECTOR_SIZE], resultado[VECTOR_SIZE];
    int suma_par = 0, suma_impar = 0;

    // Inicialización de MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Solo el proceso maestro (rank 0) inicializa los vectores
    if (rank == 0) {
        // Inicializar los vectores
        for (int i = 0; i < VECTOR_SIZE; i++) {
            vectorA[i] = i + 1; // Ejemplo de inicialización
            vectorB[i] = (i + 1) * 2; // Ejemplo de inicialización
        }
    }
        printf("Vector A:\n");
        for (int i = 0; i < VECTOR_SIZE; i++) {
            printf("%d ", vectorA[i]);
        }
        printf("\n");
                printf("Vector B:\n");
        for (int i = 0; i < VECTOR_SIZE; i++) {
            printf("%d ", vectorB[i]);
        }
        printf("\n");

    // Enviar los vectores a todos los procesos
    MPI_Bcast(vectorA, VECTOR_SIZE, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(vectorB, VECTOR_SIZE, MPI_INT, 0, MPI_COMM_WORLD);

    // Procesador 1 (rank 1) suma las posiciones impares
    if (rank == 1) {
        for (int i = 1; i < VECTOR_SIZE; i += 2) {
            suma_impar += vectorA[i] + vectorB[i];
        }
        // Enviar la suma al maestro
        MPI_Send(&suma_impar, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
    }

    // Procesador 2 (rank 2) suma las posiciones pares
    if (rank == 2) {
        for (int i = 0; i < VECTOR_SIZE; i += 2) {
            suma_par += vectorA[i] + vectorB[i];
        }
        // Enviar la suma al maestro
        MPI_Send(&suma_par, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }

    // Procesador 0 recopila resultados
    if (rank == 0) {
        // Recibir resultados de los procesadores 1 y 2
        MPI_Recv(&suma_impar, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&suma_par, 1, MPI_INT, 2, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Calcular el resultado final
        for (int i = 0; i < VECTOR_SIZE; i++) {
            resultado[i] = vectorA[i] + vectorB[i];
        }

        // Imprimir resultados
        printf("Suma en posiciones impares: %d\n", suma_impar);
        printf("Suma en posiciones pares: %d\n", suma_par);
        printf("Resultado final de la suma de vectores:\n");
        for (int i = 0; i < VECTOR_SIZE; i++) {
            printf("%d ", resultado[i]);
        }
        printf("\n");
    }

    // Finalización de MPI
    MPI_Finalize();
    return 0;
}
