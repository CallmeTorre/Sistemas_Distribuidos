#include <stdio.h>

int main(void){
    int number = 0;
    int number2 = 0;
    int number3 = 0;
    int number4 = 0;
    int smaller1 = 0;
    int smaller2 = 0;
    int greater1 = 0;
    int greater2 = 0;
    int smallest = 0;
    int greatest = 0;

	printf("Enter four integers: ");
    scanf("%d %d %d %d", &number, &number2, &number3, &number4);

    if(number > number2){
        greater1 = number;
        smaller1 = number2;
    }else{
        greater1 = number2;
        smaller1 = number;
    }

    if(number3 > number4){
        greater2 = number3;
        smaller2 = number4;
    }else{
        greater2 = number4;
        smaller2 = number3;
    }

    if(greater1 > greater2){
        greatest = greater1;
    }else{
        greatest = greater2;
    }

    if(smaller1 > smaller2){
        smallest = smaller2;
    }else{
        smallest = smaller1;
    }

    printf("Largest:  %d \n", greatest);
    printf("Smallest: %d \n", smallest);
    return 0;
}