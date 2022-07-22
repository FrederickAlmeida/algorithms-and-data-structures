#include <iostream>
#include <assert.h>

using std::cout;

class AList {
private:
    int maxsize;        // tamanho maximo do array
    int listsize;       // tamanho atual
    int curr;           // posição atual do cursor
    int* listarray;      // ponteiro para o array com os valores

public:
    AList (int size) {
        maxsize = size;
        listsize = curr = 0;        // tamano inicial da lista e a posição do cursor deve começar em 0
        listarray = new int[size];

    }

    void insert(int valor) {
        if (listsize >= maxsize) 
            cout << "Lista cheia";
        else {
        
        for (int i = listsize; i > curr; i--) {         // mover todos os elementos após o cursor, para "liberar" uma posição
            listarray[i] = listarray[i - 1];
        }
        listarray[curr] = valor;
        listsize++;
        }
    }

    int remove() {
        if (curr >= 0 && curr < listsize) {
            int value = listarray[curr];

            for (int i = curr; i < listsize - 1; i++) {
                listarray[i] = listarray[i + 1];
            }

            listsize--;
            return value;
        }
        else
            return NULL;
    }

    void clear() {          // reiniciar a lista
        delete[] listarray;
        listsize = curr = 0;
        listarray = new int[maxsize];
    }

    void append(int value) {
        if (listsize < maxsize)
            listarray[listsize++] = value;
        else
            cout << "Lista cheia";
    }

    void moveToStart() {
        curr = 0;
    }

    void modeToEnd() {
        curr = listsize;
    }

    void prev() {
        if (curr > 0)
            curr--;
    }

    void next() {
        if (curr < listsize)
            curr++;
    }

    int length() {
        return listsize;
    }

    int currPos() {
        return curr;
    }

    void moveToPos(int position) {
        if (position >= 0 && position <= listsize)
            curr = position;
        else
            cout << "Position fora de range";
    }

    int getValue() {
        if (curr >= 0 && curr < listsize)
            return listarray[curr];
        else
            return NULL;
    }
};

int main() {
    AList lista1(5);

    lista1.insert(5);
    lista1.insert(7);
    lista1.append(4);
    lista1.moveToPos(1);
    lista1.insert(3);
    for (int i = 0; i < 4; i++) {
        lista1.moveToPos(i);
        cout << lista1.getValue() << "\n";
    }


    return 0;
}