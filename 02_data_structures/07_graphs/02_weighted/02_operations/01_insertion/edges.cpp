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


    void addEdge(int u, int v, int w) {
        if (u >= V || v >= V) {
            cout << "Invalid vertex index\n";
            return;
        }
        adj[u].push_back({v, w});
        if (!isDirected) {
            adj[v].push_back({u, w});
        }
    }
};

int main() {
     WeightedGraph wg; 
}
