#include <stdio.h>
int suma(int a, int b) {
    return a + b;
}
int resta(int a, int b) {
    return a - b;
}
int multiplicacion(int a, int b) {
    return a * b;
}
float division(int a, int b) {
    if (b != 0) {
        return (float) a / b;
    } else {
        printf("Error: División por cero no permitida.\n");
        return 0; 
    }
}
int main(){
    int num1,num2;
    int resp;
    float resp_div;
    printf("Introduce el primer numero: ");
    scanf("%d", &num1);
    printf("Introduce el segundo numero: ");
    scanf("%d", &num2);

    resp=suma(num1,num2);
    printf("resultado de la suma: %d\n ",resp);
    resp=resta(num1,num2);
    printf("resultado de la resta: %d\n ",resp);
    resp=multiplicacion(num1,num2);
    printf("resultado de la multiplicacion: %d\n ",resp);
    resp_div=division(num1,num2);
    printf("resultado de la division: %.2f\n ",resp_div);
}
