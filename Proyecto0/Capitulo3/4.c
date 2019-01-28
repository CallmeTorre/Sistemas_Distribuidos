#include <stdio.h>

int main(void){
    int lada = 0; 
    int part1 = 0;
    int part2 = 0;

	printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d", &lada, &part1, &part2);

    printf("You entered  %.3d.%.3d.%.4d\n", lada, part1, part2);
    return 0;
}