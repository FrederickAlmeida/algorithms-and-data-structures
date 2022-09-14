#include <iostream>
#include <stack>

using std::cout;
using std::stack;

class graph {
private:
    int** matrix;
    int numEdge;
    int* mark;
    int nodes;

public:
    graph(int n) {
        matrix = new int*[n];
        mark = new int[n];
        for (int i = 0; i < n; i++) matrix[i] = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
        numEdge = 0;
        nodes = n;
    }

    int first(int v) {
        for (int i = 0; i < nodes; i++) {
            if (matrix[v][i] != 0)  return i;
        }

        return nodes;
    }

    int next(int v, int w) {
        for (int i = w+1; i < nodes; i++) {
            if (matrix[v][i] != 0)  return i;
        }

        return nodes;
    }

    void setEdge(int i, int j, int wt) {
        if (wt != 0) {
            if (matrix[i][j] = 0)   numEdge++;
            matrix[i][j] = wt;
        }
    }

    void delEdge(int i, int j) {
        if (matrix[i][j] != 0)  numEdge--;
        matrix[i][j] = 0;
    }
    
    void print() {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void setMark(int v, int status) {mark[v] = status;}
    int getMark(int v)  {return mark[v];}

    void graphTraverse(stack<int> &s) {
        int v;
        for (v = 0; v < nodes; v++) setMark(v, 0);
        for (v = 0; v < nodes; v++) {
            if (getMark(v) == 0)    toposort(v, s);
        }
    }

    void toposort(int v, stack<int> &s) {
        setMark(v, 1);
        int w = first(v);
        while (w < nodes) {
            if (getMark(w) == 0)    toposort(w, s);
            w = next(v, w);
        }
        s.push(v);
    }
};


int main() {
    graph teste(7);
    stack<int> stacktest;
    teste.setEdge(0, 1, 1);
    teste.setEdge(0, 2, 1);
    teste.setEdge(1, 3, 1);
    teste.setEdge(1, 4, 1);
    teste.setEdge(1, 5, 1);
    teste.setEdge(2, 3, 1);
    teste.setEdge(3, 4, 1);
    teste.setEdge(4, 6, 1);
    teste.graphTraverse(stacktest);
    while (!stacktest.empty()) {
        cout << stacktest.top() << " ";
        stacktest.pop();
    }
}