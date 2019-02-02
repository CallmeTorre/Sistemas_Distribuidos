#include <stdio.h>

int main(void) {
    float number;
    float greatest = 0.0f;

    do{
        printf("Enter a number: ");
        scanf("%f", &number);

        if(number > greatest)
            greatest = number;

    }while(number > 0);

    printf("\nThe largest number entered was %f\n", greatest);

    return 0;
}