#include <iostream>
#include <queue>

using std::cout;
using std::queue;

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

    void graphTraverse() {
        int v;
        for (v = 0; v < nodes; v++) setMark(v, 0);
        for (v = 0; v < nodes; v++) {
            if (getMark(v) == 0)    BFS(v);
        }
    }

    void BFS(int start) {
        queue<int> Q; int v, w;
        Q.push(start);
        setMark(start, 1);

        while (Q.size() > 0) {
            v = Q.front();  Q.pop();
            cout << v << " ";
            w = first(v);
            while(w < nodes) {

                if (getMark(w) == 0) {
                    setMark(w, 1);
                    Q.push(w);
                }

                w = next(v, w);
            }
            //posvisit
        }

    }
};


int main() {
    graph teste(5);
    teste.setEdge(0, 1, 1);
    teste.setEdge(1, 0, 1);
    teste.setEdge(1, 3, 1);
    teste.setEdge(3, 1, 1);
    teste.setEdge(0, 3, 1);
    teste.setEdge(3, 0, 1);
    teste.setEdge(3, 4, 1);
    teste.setEdge(4, 3, 1);
    teste.setEdge(3, 2, 1);
    teste.setEdge(2, 3, 1);
    teste.setEdge(2, 4, 1);
    teste.setEdge(4, 2, 1);
    teste.graphTraverse();
}