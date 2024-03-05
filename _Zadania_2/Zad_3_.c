#include <stdio.h>

struct Point
{
    int x;
    int y;
};

struct Rectangle
{
    struct Point a;
    struct Point b;
};
void move(struct Point* p){
    p->x+=5;
    p->y+=5;
}
int calculateArea(struct Rectangle r1)
{
    int width=r1.b.x-r1.a.x;
    int height=r1.a.y-r1.b.y;
    return width*height;
}
int calculateCircumference(struct Rectangle r1)
{
    int width=r1.b.x-r1.a.x;
    int height=r1.a.y-r1.b.y;
    return 2*(width+height);
}
int main() {
    struct Point p1={1,2};
    printf("Wstepne wspolrzedne: [%d, %d]\n", p1.x, p1.y);
    move(&p1);
    printf("Zmienione wspolrzedne: [%d, %d]\n", p1.x, p1.y);

    struct Rectangle r1={{1,4}, {6,1}};
    printf("Pole: %d\n", calculateArea(r1));
    printf("Obwod: %d\n", calculateCircumference(r1));

    return 0;
}
