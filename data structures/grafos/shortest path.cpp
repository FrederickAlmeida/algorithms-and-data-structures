#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using std::string;


class player {
public:
    string name;
    int index;
    int distancia;
    int ahmedindex;

    player(string pname, int pindex) {
        if (pname == "Ahmed")   ahmedindex = pindex;
        name = pname;
        index = pindex;
    }
};


class graph {
public:
    int** matrix;
    int numEdge;
    int* mark;
    int nodes;

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

    void setEdge(int i, int j, int wt) {
        if (wt != 0) {
            if (matrix[i][j] = 0)   numEdge += 2;
            matrix[i][j] = wt;
            matrix[j][i] = wt;
        }
    }

    void print() {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

// int binsearch(vector<player> list, string name) {
//     int left = 0, m;
//     int right = list.size();

//     while (left < right) {
//         m = (left+right)/2;
//         if (list[m].name == name) return 1;
//         else if (name < list[m].name) right = m-1;
//         else left = m+1;
//     }

//     return 0;
// }

int foiadicionado(vector<player> list, string name) {
    vector<player>::iterator it;
    for (it = list.begin(); it !=  list.end(); it++) {
        if (it->name == name)   return 1;
    }

    return 0;
}

int main() {
    vector<player> jadd;
    player* p;
    int cases, teams, index=0, presize;
    string name1, name2, name3;

    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cin >> teams;
        graph teste(3*teams);
        

        for (int j = 0; j < teams; j++) {
            presize = jadd.size();
            cin >> name1;
            if (foiadicionado(jadd, name1) == 0) {
                p = new player(name1, index++);
                jadd.push_back(*p);

            }

            cin >> name2;
            if (foiadicionado(jadd, name2) == 0) {
                p = new player(name2, index++);
                jadd.push_back(*p);

            }

            cin >> name3;
            if (foiadicionado(jadd, name3) == 0) {
                p = new player(name3, index++);
                jadd.push_back(*p);

            }
            
            if ((jadd.size() - presize) == 2) {
                teste.setEdge(jadd[presize+1].index, jadd[presize+2].index, 1);

            } else if ((jadd.size() - presize) == 3) {
                teste.setEdge(jadd[presize+1].index, jadd[presize+2].index, 1);
                teste.setEdge(jadd[presize+2].index, jadd[presize+3].index, 1);
                teste.setEdge(jadd[presize+1].index, jadd[presize+3].index, 1);
            }

        }

        teste.print();
    }
}