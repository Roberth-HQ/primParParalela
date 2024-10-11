#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 3 

void mostrar_matriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int rank, size;
    int A[N][N], B[N][N], C[N][N] = {0};

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        int r = 1;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                A[i][j] = r; // Inicialización de la matriz A
                B[i][j] = r; // Inicialización de la matriz B
                r++;
            }

        printf("Matriz A:\n");
        mostrar_matriz(A);
        printf("Matriz B:\n");
        mostrar_matriz(B);

        // Enviar la matriz B a todos los procesos
        for (int i = 1; i < size; i++) {
            MPI_Send(B, N * N, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } else {
        // Recibir la matriz B
        MPI_Recv(B, N * N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    // Bcast de la matriz A a todos los procesos
    if (rank == 0) {
        MPI_Bcast(A, N * N, MPI_INT, 0, MPI_COMM_WORLD);
    } else {
        MPI_Bcast(A, N * N, MPI_INT, 0, MPI_COMM_WORLD);
    }

    // Dividir filas para que cada proceso calcule su parte
    int rows_per_process = N / size;  // Filas por proceso
    int start_row = rank * rows_per_process;
    int end_row = (rank + 1) * rows_per_process;

    // Asegurarse de que el último proceso maneje cualquier fila restante
    if (rank == size - 1) end_row = N;

    // Cada proceso multiplica su parte de la matriz A por B
    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Recopilar resultados en el proceso 0
    if (rank == 0) {
        // Copiar resultados locales
        for (int i = start_row; i < end_row; i++) {
            for (int j = 0; j < N; j++) {
                C[i][j] = C[i][j];
            }
        }

        // Recoger resultados de otros procesos
        for (int i = 1; i < size; i++) {
            MPI_Recv(&C[i * rows_per_process], (i == size - 1 ? N - i * rows_per_process : rows_per_process) * N, MPI_INT, i, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        printf("Matriz C (Resultado):\n");
        mostrar_matriz(C);
    } else {
        // Enviar parte calculada de la matriz C
        MPI_Send(&C[start_row], (end_row - start_row) * N, MPI_INT, 0, 1, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}

