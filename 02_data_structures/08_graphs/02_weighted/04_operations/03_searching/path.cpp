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

    bool dfsPath(int u, int v, vector<bool>& visited) const {
        if (u == v) return true;
        visited[u] = true;
        for (auto& edge : adj[u]) {
            if (!visited[edge.dest] && dfsPath(edge.dest, v, visited)) {
                return true;
            }
        }
        return false;
    }

public:
    WeightedGraph(int V = 0, bool directed = false) {
        this->V = V;
        isDirected = directed;
        adj.resize(V);
    }

    bool pathExists(int u, int v) const {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            return false;
        }
        vector<bool> visited(V, false);
        return dfsPath(u, v, visited);
    }
};

int main() {
    WeightedGraph wg;
}
