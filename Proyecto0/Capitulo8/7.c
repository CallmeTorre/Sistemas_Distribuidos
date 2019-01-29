#include <stdbool.h> 
#include <stdio.h>

int main(void) {

    int matrix[5][5];
    int temp = 0;

    for(int i = 0; i < 5; i++){
        printf("Enter row %d: ", i + 1);

        for(int j = 0; j < 5; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Row totals: ");

    for(int i = 0; i < 5; i++){
        temp = 0;
        for(int j = 0; j < 5; j++){
            temp += matrix[i][j];
        }
        printf("%d ", temp);
    }
    printf("\n");

    printf("Column totals: ");

    for(int i = 0; i < 5; i++){
        temp = 0;
        for(int j = 0; j < 5; j++){
            temp += matrix[j][i];
        }
        printf("%d ", temp);
    }
    printf("\n");

    return 0;
}