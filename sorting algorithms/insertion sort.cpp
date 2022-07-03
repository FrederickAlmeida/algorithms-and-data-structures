#include <iostream>

using std::cin;
using std::cout;

void insort(int* array, int size) {
    int v, j;

    for (int i = 1; i < size; i++) {
        v = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > v) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = v;
    }
}

int main() {
    int array[] = {42, 20, 17, 13, 28, 14, 23, 15};
    int size;

    size = sizeof(array)/sizeof(int);

    insort(array, size);
    
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    return 0;
}