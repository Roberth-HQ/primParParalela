#include <stdio.h>

void suma(int a, int b, int *resultado) {
    *resultado = a + b;  
}
void resta(int a, int b, int *resultado) {
    *resultado = a - b;  
}
void multiplicacion(int a, int b, int *resultado) {
    *resultado = a * b;  
}
void division(int a, int b, float *resultado) {
    if (b != 0) {
        *resultado = (float)a / b;  
    } else {
        printf("Error: División por cero no permitida.\n");
        *resultado = 0;  
    }
}

int main() {
    int num1, num2;
    int resp;
    float resp_div;  
    printf("Introduce el primer numero: ");
    scanf("%d", &num1);
    printf("Introduce el segundo numero: ");
    scanf("%d", &num2);

    suma(num1, num2, &resp);  
    printf("resultado de la suma: %d\n", resp);
    resta(num1, num2, &resp);
    printf("resultado de la resta: %d\n", resp);
    multiplicacion(num1, num2, &resp); 
    printf("resultado de la multiplicacion: %d\n", resp);
    division(num1, num2, &resp_div); 
    printf("resultado de la division: %.2f\n", resp_div);

    return 0;
}
