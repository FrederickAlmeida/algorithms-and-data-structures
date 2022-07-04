#include <iostream>

using std::cin;
using std::cout;

void merge(int *array, int left, int right) {
    int* array_temp = new int[right+1];

    for (int i = left; i <= right; i++) {
        array_temp[i] = array[i];
    }

    int mid, i1, i2;
    mid = (left + right) / 2;
    i1 = left;
    i2 = mid + 1;
    
    for (int curr = left; curr <= right; curr++) {
        if (i1 == (mid + 1))
            array[curr] = array_temp[i2++];
        else if (i2 > right)
            array[curr] = array_temp[i1++];
        else if (array_temp[i1] <= array_temp[i2])
            array[curr] = array_temp[i1++];
        else
            array[curr] = array_temp[i2++];
    }

    delete[] array_temp;
}

void mergesort(int* array, int left, int right) {
    int mid;
    mid = (left + right) / 2;

    if (left < right) {
        mergesort(array, left, mid);
        mergesort(array, (mid + 1), right);
        merge(array, left, right);
    }
}

int main() {
    int array[] = { 42, 20, 17, 13, 28, 14, 23, 15 };
    int size, left, right;

    size = sizeof(array) / sizeof(int);
    left = 0;
    right = size - 1;

    mergesort(array, left, right);

    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    return 0;
}
