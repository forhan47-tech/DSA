#include <iostream>
#include <vector>
#include <list>
using namespace std;

class WeightedGraph {
    int V; 
    bool isDirected;
    vector<list<pair<int,int>>> adj;

public:
    WeightedGraph(int V = 0, bool directed = false) {
        this->V = V; 
        isDirected = directed; 
        adj.resize(V);
    }

    void removeEdge(int u, int v) {
        adj[u].remove_if([v](auto p){ return p.first == v; });
        if (!isDirected) {
            adj[v].remove_if([u](auto p){ return p.first == u; });
        }
    }
};

int main() {
     WeightedGraph wg; 
}
