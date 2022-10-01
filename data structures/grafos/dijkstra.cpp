#include <iostream>
#include <vector>
#include <queue>

#define maxdistance 2000000000
typedef std::pair<int, int> pii;

using std::cout;
using std::cin;
using std::vector;
using std::priority_queue;


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
        if (wt != 0 && i != j) {
            if (matrix[i][j] == 0) {
                numEdge++;
                matrix[i][j] = wt;
            } else if (matrix[i][j] > wt) {
                matrix[i][j] = wt;
            }
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

    void setMark(int v, int status) {mark[v] = status;}
    int getMark(int v)  {return mark[v];}

    int weight(int v, int w) {return matrix[v][w];}

    void Dijkstra(int start, int* d) {
        for (int i = 0; i < nodes; i++) {
            d[i] = maxdistance;
            setMark(i, 0);
        }

        //os pairs sao no estilo: (custo acumulado ate o node x, node x)
        priority_queue<pii, vector<pii>, std::greater<pii>> H;
        H.push(std::make_pair(0, start));
        d[start] = 0;

        pii top;
        for (int i = 0; i < nodes; i++) {
            
            do {
                if (H.size() == 0) return;
                top = H.top(); H.pop();

            } while (getMark(top.second) == 1);
            setMark(top.second, 1); //P[top.second] = p;

            int w = first(top.second);
            while(w < nodes) {
                if (getMark(w) == 0 && d[w] > d[top.second] + weight(top.second, w)) {
                    d[w] = d[top.second] + weight(top.second, w);
                    H.push(std::make_pair(d[w], w));
                }
                w = next(top.second, w);
            }
        }
    }
};

int main() {
    int cases, nodes, entries, startn, endn, a, b, w;
    cin >> cases;
    int* dist = new int[20000];

    int i = 1;
    while(cases--) {
        cin >> nodes >> entries >> startn >> endn;
        graph teste(nodes);
        
        while(entries--) {
            cin >> a >> b >> w;
            teste.setEdge(a, b, w);
            teste.setEdge(b, a, w);
        }

        teste.Dijkstra(startn, dist);

        if (dist[endn] < maxdistance) {
        cout << "Case #" << i++ << ": " << dist[endn] << "\n";
        } else {
        cout << "Case #" << i++ << ": unreachable" << "\n";
        }
    }   
}