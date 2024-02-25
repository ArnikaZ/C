#include <stdio.h>

int function(int value);
int main() {

    int value;
    printf("podaj liczbe: ");
    scanf("%d", &value);
    printf("suma: %d",function(value));

    return 0;
}

int function(int value)
{
    int sum=0;
    for(int i=0;i<value;i++)
    {
        if(value<=0)
        {
            return 0;
        }
        else if(i%3==0 || i%5==0)
        {
            sum+=i;
        }

    }
    return sum;
}