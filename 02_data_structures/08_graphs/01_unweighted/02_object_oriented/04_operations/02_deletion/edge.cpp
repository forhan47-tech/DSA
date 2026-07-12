#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    void removeEdge(int u, int v) {
        if (!hasVertex(u) || !hasVertex(v)) return;
        adj[u].erase(v);
        if (!directed) adj[v].erase(u);
    }

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }
};

int main() {
    Graph g; // unweighted graph
    g.removeEdge(4, 5);
    return 0;
}
