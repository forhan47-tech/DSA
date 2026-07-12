#include <iostream>
#include <unordered_map>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    void addVertex(int v) {
        if (!hasVertex(v))
            adj[v] = unordered_map<int,int>();
    }

    void addEdge(int u, int v, int w) {
        addVertex(u);
        addVertex(v);
        adj[u][v] = w;
        if (!directed) adj[v][u] = w;
    }

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }
};

int main() {
    Graph g(false); // weighted graph

    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 3);
    
    return 0;
}
