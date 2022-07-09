#include <iostream>

using std::cout;

void print(int* array,int size) {
  for (int i = 0; i < size-1; i++) {
    cout << array[i] << " ";
  }
  cout << array[size-1] << '\n';
}

void swap(int& element1, int& element2) {
  int temp_element;
  
  temp_element = element1;
  element1 = element2;
  element2 = temp_element;
}

int hoarepartition(int* array, int l, int r) {
  int i, j, p;
  p = array[l];
  i = l;
  j = r+1;

  do {
    
    do {
      i++;
    } while ((i < r) && (array[i] < p));
// tem que incrementar até a[i] < p, pq se achar um elemento igual a p, será necessário realizar o swap desse elemento, pq ele provavelmente está antes do pivô

    do {
      j--;
    } while ((array[j] > p));

    swap(array[i], array[j]);
  } while (i < j) ;
  
  swap(array[i], array[j]);
  swap(array[l], array[j]);
  return j;
}

int binarysearch(int* array, int k, int size) {
  int l = 0, r = size-1, m;

  while (l <= r) {
    m = (l + r) / 2;
    
    if (array[m] == k) {
        return m;
    } else if (k < array[m]) {
        r = m - 1;
    } else {
        l = m + 1;
    }
  }
  
  return -1;
}

void quicksort(int* array,int l,int r) {
  // rodar essa recursão até chegar em um subarray unitario
  if (l < r) {
    int s;
  
    s = hoarepartition(array, l, r);
    quicksort(array, l, s-1);
    quicksort(array, s+1, r);
    }
}

int main() {
  int array[] = {42, 20, 17, 13, 28, 14, 23, 15, 28, 12, 15, 182, 129, 22, 112, 192, 281, 11, 95, 842, 26, 7449, 38, 29, 47, 18};
  int size, l, r;

  size = sizeof(array)/sizeof(int);
  l = 0;
  r = size - 1;

  quicksort(array, l, r);
  print(array, size);

  cout << binarysearch(array, 28, l, r) << '\n';

  return 0;
}
