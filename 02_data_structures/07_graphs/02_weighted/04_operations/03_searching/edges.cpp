#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
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

    bool hasEdge(int u, int v) const {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cerr << "Invalid vertex index\n";
            return false;
        }
        return any_of(adj[u].begin(), adj[u].end(),
                      [&](const Edge& e){ return e.dest == v; });
    }
};

int main() {
    WeightedGraph wg;
}
