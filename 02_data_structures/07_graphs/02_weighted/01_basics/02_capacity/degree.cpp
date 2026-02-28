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

    int degree(int u) const { 
        return adj[u].size(); 
    }
};

int main() {
    WeightedGraph wg;
}