#include <stdio.h>

int main() {
    int grades[2][5]={{2,3,4,4,5},{5,6,3,4,4}};
    double avgMath;
    double sumM=0;
    for(int j=0;j<5;j++){
        sumM+=grades[0][j];
        }
    avgMath=sumM/5;
    printf("Srednia ocen z matematyki: %.1f\n", avgMath);
    double avgPhys;
    double sumP=0;
    for(int j=0;j<5;j++){
        sumP+=grades[1][j];
    }
    avgPhys=sumP/5;
    printf("Srednia ocen z fizyki: %.1f\n", avgPhys);
    return 0;
}
