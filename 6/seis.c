#include <stdio.h>

void fibonacci(int n) {
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    for (int i = 0; i < n; i++) {
        printf("%d \n", fib[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Ingresa el numero para la secuencia de Fibonacci: ");
    scanf("%d", &n);
    if (n >= 2) {
        fibonacci(n);
    } else {
        printf("El valor de n debe ser al menos 2.\n");
    }
    return 0;
}