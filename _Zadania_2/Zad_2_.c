#include <stdio.h>

void function(float *value)
{
    (*value)*=2;
}
int main() {
    float value=1.1;
    function(&value);
    printf("%.2f", value);
    return 0;
}
