#include <stdio.h>

int main(void){
    int num1 = 0; 
    int denom1 = 0;
    int num2 = 0;
    int denom2 = 0;
    int result_sum = 0;
    int common_denom = 0;

	printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);

    result_sum = (num1 * denom2) + (num2 * denom1); 
    common_denom = denom1 * denom2;

    printf("You entered %d/%d\n", result_sum, common_denom);
    return 0;
}