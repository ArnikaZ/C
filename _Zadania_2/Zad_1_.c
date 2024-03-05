#include <stdio.h>

int main() {
    int value=5;
    int * p_value=&value;
    *p_value+=1;
    printf("%d\n", *p_value);
    printf("%d",value);
    return 0;
}
