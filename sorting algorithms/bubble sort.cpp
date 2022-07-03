#include <iostream>

using std::cin;
using std::cout;

void swap(int& arr1, int& arr2) {
    int temp;
    temp = arr1;
    arr1 = arr2;
    arr2 = temp;
}

void bubsort(int* array, int size) {
    int temp;

    for (int i = 0; i < (size - 1); i++) {
        for (int j = 0; j < (size - 1 - i); j++) {
            if (array[j+1] < array[j]){
                swap(array[j], array[j+1]);
            }
        }
    }
}

int main(){
    int array[] = {42, 20, 17, 13, 28, 14, 23, 15};
    int size;

    size = sizeof(array)/sizeof(int);

    bubsort(array, size);
    
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    return 0;
}