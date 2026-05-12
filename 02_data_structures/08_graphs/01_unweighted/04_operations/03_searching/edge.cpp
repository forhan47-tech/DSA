#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
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

    bool hasEdge(int u, int v) const {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cerr << "Invalid vertex index\n";
            return false;
        }
        return find(adj[u].begin(), adj[u].end(), v) != adj[u].end();
    }
};

int main() {
    Graph g;
}