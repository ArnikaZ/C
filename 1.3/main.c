#include <stdio.h>

int factorial(int a);
void function(int array[], int arraySize);
int main() {
    int array[]={1,2,3,4,5,6,7,8,9,10};
    function(array,10);

    return 0;
}

int factorial(int a){
    if(a==0) return 1;
    else
        return a* factorial(a-1);
}

void function(int array[], int arraySize)
{
    for(int i=0;i<arraySize;i++)
    {
        printf("%d\n", factorial(array[i]));
    }
}