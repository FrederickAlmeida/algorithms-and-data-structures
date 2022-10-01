#include <iostream>
#include <vector>
#include <queue>

#define maxdistance 2000000000

using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;
using std::pair;

class Node {
public:
    int v;
    int weight;

    Node(int vert, int wt) {
        v = vert;
        weight = wt;
    }

    void updatew(int w) {
        weight = w;
    }
};


class Graph {
private:
    int nodes;
    vector<Node>* adj;
    int* mark;

public:
    Graph(int n) {
        nodes = n;
        adj = new vector<Node>[n];
        mark = new int[n];
    }

    void addEdge(int u, int v, int wt) {
        if (wt >= 0 && u != v) {
            bool isthere = false;

            vector<Node>::iterator it;
            for (it = adj[u].begin(); it != adj[u].end(); it++) {
                if (it->v == v) {
                    isthere = true;

                    if (it->weight > wt) {
                        it->weight = wt;
                        
                        vector<Node>::iterator it2;
                        for (it2 = adj[v].begin(); it2 != adj[v].end(); it2++) {
                            if (it2->v == u) {
                                it2->weight = wt;
                            }
                        }
                    }
                }
            }

            if (isthere == false) {
                Node* p = new Node(v, wt);
                adj[u].push_back(*p);
                p = new Node(u, wt);
                adj[v].push_back(*p);
            }
        }
    }

    void setMark(int i, int status) {mark[i] = status;}
    int getMark(int i) {return mark[i];}

    int weight(int v, int w) {
        for (auto it: adj[v]) {
            if (it.v == w) return it.weight;
        }
    }

    void Dijkstra(int start, int*d) {
        for (int i = 0; i < nodes; i++) {
            d[i] = maxdistance;
            setMark(i, 0);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> H;
        H.push(std::make_pair(0, start));
        d[start] = 0;

        pair<int, int> top;
        for (int i = 0; i < nodes; i++) {

            do {
                if (H.size() == 0) return;
                top = H.top(); H.pop();

            } while(getMark(top.second) == 1);
            setMark(top.second, 1);

            for (auto w: adj[top.second]) {
                if (getMark(w.v) == 0 && d[w.v] > d[top.second] + weight(top.second, w.v)) {
                    d[w.v] = d[top.second] + weight(top.second, w.v);
                    H.push(std::make_pair(d[w.v], w.v));
                }
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
        Graph teste(nodes);
        
        while(entries--) {
            cin >> a >> b >> w;
            teste.addEdge(a, b, w);
        }

        teste.Dijkstra(startn, dist);

        if (dist[endn] < maxdistance) {
        cout << "Case #" << i++ << ": " << dist[endn] << "\n";
        } else {
        cout << "Case #" << i++ << ": unreachable" << "\n";
        }
    } 
}