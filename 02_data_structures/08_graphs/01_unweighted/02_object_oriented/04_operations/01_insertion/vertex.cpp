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

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }
};

int main() {
    Graph g; // unweighted graph
    g.addVertex(4);
    return 0;
}
