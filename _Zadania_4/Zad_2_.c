#include <stdio.h>



int search(int *array, int left, int right, int target){
    if (right>=left) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            return search(array, left, mid - 1, target);
        } else {
            return search(array, mid + 1, right, target);
        }
    }
    return -1;
}

int main() {
    int tab[]={2,4,5,6,7,10,12};
    int target=12;
    int index = search(tab,0,6,target);
    printf("%d", index);
    return 0;
}
