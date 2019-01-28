#include <stdio.h>

int main(void){
    int number = 0;
    int result = 0;

	printf("Enter a number: ");
    scanf("%d", &number);

    if(number >= 0 && number <= 9)
        result = 1;
    else if(number >= 10 && number <= 99)
        result = 2;
    else if(number >= 100 && number <= 999)
        result = 3;
    else if(number >= 1000 && number <= 9999)
        result = 4;

    printf("The number %d has %d digits\n", number, result);
    return 0;
}