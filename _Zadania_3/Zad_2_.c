#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int **createMatrix(int rows, int cols){
    int **matrix=(int **) malloc(rows * sizeof(int **));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand()%100;
        }
    }
    return matrix;
}

void printMatrix(int **matrix, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows, cols;
    printf("Podaj liczbe wierszy: \n");
    scanf("%d", &rows);
    printf("Podaj liczbe kolumn: \n");
    scanf("%d", &cols);

    srand(time(NULL));
    int **matrix= createMatrix(rows,cols);
    printMatrix(matrix,rows,cols);
    freeMatrix(matrix,rows);
    return 0;
}
