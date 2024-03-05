#include <stdio.h>

struct Student
{
    char name[50];
    double grade;
};

void sort(struct Student tab[], int size)
{
    struct Student temp;
    for(int i=0;i<size;i++)
    {
        for(int j=0; j<size-1-i;j++)
        {
            if(tab[j].grade<tab[j+1].grade)
            {
                temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}
int main() {
    struct Student tab[100]={
            {"Jan", 3},
            {"Adam", 5},
            {"Anna", 4},
            {"Kamil", 2},
            {"Marek", 6}
    };
    sort(tab, 100);
    for(int i=0;i<100;i++)
    {
        printf("%s, %.2f\n", tab[i].name, tab[i].grade);
    }

    return 0;
}
