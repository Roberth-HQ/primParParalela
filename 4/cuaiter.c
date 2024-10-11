#include <stdio.h>

void calcularPiIterativo(int *iteraciones, double *resultado) {
    double pi = 0.0;
    int signo = 1;
    
    for (int i = 0; i < *iteraciones; i++) {
        pi += signo * (4.0 / (2 * i + 1));
        signo = -signo; 
    }
    *resultado = pi;
}

int main() {
    int iteraciones = 1000000; 
    double pi = 0.0;
    
    calcularPiIterativo(&iteraciones, &pi);
    
    printf("Aproximacion de Pi (Iterativa): %f\n", pi);
    
    return 0;
}
