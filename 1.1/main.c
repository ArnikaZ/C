#include <stdio.h>


int main() {
    printf("Podaj swoje imie :");
    char name[50];
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    return 0;
}
