#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    void addVertex(int v) {
        if (!hasVertex(v))
            adj[v] = unordered_set<int>();
    }

    void addEdge(int u, int v) {
        addVertex(u);
        addVertex(v);
        adj[u].insert(v);
        if (!directed) adj[v].insert(u);
    }

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }
};

int main() {
    Graph g; // unweighted graph

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(6, 7);

    return 0;
}
