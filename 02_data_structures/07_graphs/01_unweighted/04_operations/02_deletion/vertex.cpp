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

    void removeVertex(int u) {
        if (V == 0 || u < 0 || u >= V) {
            cerr << "Invalid vertex index\n";
            return;
        }

        for (int i = 0; i < V; i++) {
            adj[i].remove(u);
        }

        adj[u].clear();
    }
};

int main() {
    Graph g;
}