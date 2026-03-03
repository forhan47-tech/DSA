#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;                  
    bool isDirected;        
    vector<list<int>> adj;  

public:
    Graph(int V = 0, bool directed = false) {
        this->V = V;
        isDirected = directed;
        adj.resize(V);
    }

    void removeEdge(int u, int v) {
        if (V == 0 || u < 0 || u >= V || v < 0 || v >= V) {
            cerr << "Invalid vertex index\n";
            return;
        }
        
        adj[u].remove(v);
        if (!isDirected) {
            adj[v].remove(u);
        }
    }
};

int main() {
    Graph g;
}