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

    bool hasEdge(int u, int v) const {
        return find(adj[u].begin(), adj[u].end(), v) != adj[u].end();
    }
};

int main() {
    Graph g;
}