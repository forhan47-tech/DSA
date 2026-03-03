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

    int countEdges() const {
        if (V == 0) return 0; 
        int total = 0;
        for (int i = 0; i < V; i++) {
            total += adj[i].size();
        }
        return isDirected ? total : total / 2;
    }
};

int main() {
    WeightedGraph wg;
}
