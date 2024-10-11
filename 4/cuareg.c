#include <stdio.h>

void calcularPiRecursivo(int *iteraciones, int actual, double *resultado, int signo) {
    if (actual >= *iteraciones) {
        return;
    }
    *resultado += signo * (4.0 / (2 * actual + 1));
    calcularPiRecursivo(iteraciones, actual + 1, resultado, -signo); 
}

int main() {
    int iteraciones = 1000000; 
    double pi = 0.0;
    calcularPiRecursivo(&iteraciones, 0, &pi, 1);
    printf("Aproximacion de Pi (Recursiva): %f\n", pi);
    return 0;
}
