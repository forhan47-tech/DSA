#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Edge {
public:
    int dest;
    int weight;
};

class WeightedGraph {
    int V;
    bool isDirected;
    vector<list<Edge>> adj;

public:
    WeightedGraph(int V = 0, bool directed = false) {
        this->V = V; 
        isDirected = directed;
        adj.resize(V);
    }

    void removeVertex(int u) {
        if (u >= V) {
            return;
        } 
        for (int i = 0; i < V; i++) {
            adj[i].remove_if([&](const Edge& e){ return e.dest == u; });
        }
        adj[u].clear();
    }
};

int main() {
    WeightedGraph wg;
}