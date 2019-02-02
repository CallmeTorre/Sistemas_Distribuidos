#include <stdbool.h> 
#include <stdio.h>

int main(void) {

    bool seen_number[10] = {false};
    bool repeated[10] = {false};
    int numero = 0;
    int check_num = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &numero);

    while(numero > 0){
        check_num = numero % 10;
        if(seen_number[check_num]){
            repeated[check_num] = true;
        }
        seen_number[check_num] = true;
        numero /= 10;
    }

    printf("Repeated digit(s): ");
    for(int i = 0; i < 10; i++){
        if(repeated[i]){
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}