#include <stdio.h>

int main(void) {

    int numero = 0;
    int resultado = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &numero);

    for(int i = 1; i <= numero; i++){
        resultado = resultado * i;
    }

    printf("Factorial of %d: %d\n", numero, resultado);

    return 0;
}