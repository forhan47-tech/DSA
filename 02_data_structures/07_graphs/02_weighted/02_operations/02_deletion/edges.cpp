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

    void removeEdge(int u, int v) {
        adj[u].remove_if([&](const Edge& e){ return e.dest == v; });
        if (!isDirected) {
            adj[v].remove_if([&](const Edge& e){ return e.dest == u; });
        }
    }
};

int main() {
    WeightedGraph wg;
}