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

    int getWeight(int u, int v) const {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cerr << "Invalid vertex index\n";
            return -1;
        }
        for (const auto& edge : adj[u]) {
            if (edge.dest == v) {
                return edge.weight;
            }
        }
        return -1;
    }
};

int main() {
    WeightedGraph wg;
}
