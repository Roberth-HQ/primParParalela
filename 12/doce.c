#include <stdio.h>
#include <omp.h>

int main() {
    int n;
    printf("Ingrese el número de términos de la serie Fibonacci a generar: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("El número debe ser al menos 2 para generar la serie.\n");
        return 1;
    }

    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    // Regiones paralelas de OpenMP
    #pragma omp parallel shared(fib, n)
    {
        #pragma omp for
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
    }


    printf("Serie Fibonacci: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return 0;
}
