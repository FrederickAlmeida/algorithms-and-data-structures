#include <iostream>

using std::cout;
using std::cin;

void bottomup(int* H, int tamanho) {
    int k, v, j;
    bool heap;

    for (int i = tamanho/2; i >= 1; i--) {
        k = i;
        v = H[k];
        heap = false;

        while (!(heap) && 2*k <= tamanho) {
            j = 2*k;

            if (j < tamanho) 
                if (H[j] > H[j+1])  j = j + 1;
            
            if (v <= H[j])
                heap = 1;
            else {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

void heapsort(int* array, int tamanho) {
    int temp;
    while (tamanho > 1) {
        temp = array[1];
        array[1] = array[tamanho];
        array[tamanho] = temp;

        tamanho--;
        bottomup(array, tamanho);
    }
}

void print(int* H, int tamanho) {
    for (int i = 1; i <= tamanho; i++) {
        cout << H[i] << " ";
    }
    cout << "\n";
}

int main() {
    int tamanho, custo, n1, n2, t;
    int* array;

    while (cin >> tamanho && tamanho != 0) {
        custo = 0;
        array = new int[tamanho+1];

        for (int j = 1; j <= tamanho; j++) {
            cin >> array[j];
        }

        bottomup(array, tamanho);

        t = tamanho;
        for (int i = 1; i < t; i++) {
            n1 = array[1];
            array[1] = array[tamanho];

            bottomup(array, tamanho);
            n2 = array[1];
            custo += n1+n2;

            array[1] = n1+n2;
            tamanho--;
            bottomup(array, tamanho);
        }
        cout << custo << "\n";
        
        delete array;
    }
}
