#include <stdio.h>
#include <stdlib.h>

int pascal(int row, int col){
    if (col==0 || col==row){
        return 1;
    } else{
        return pascal(row-1, col-1)+ pascal(row-1, col);
    }
}

void printPascal(int height){
    int **triangle = (int **)malloc(height * sizeof(int *));

    for (int i = 0; i < height; i++) {
        triangle[i] = (int *)malloc((i + 1) * sizeof(int));

        for (int j = 0; j <= i; j++) {
            triangle[i][j] = pascal(i, j);
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        free(triangle[i]);
    }
    free(triangle);

}

int main() {
    int height;
    printf("Podaj wysokosc trojkata: ");
    scanf("%d", &height);
    printPascal(height);

    return 0;
}
