#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    int vertexCount() const { return adj.size(); }

    int edgeCount() const {
        int count = 0;
        for (auto& pair : adj) count += pair.second.size();
        return directed ? count : count / 2;
    }

    double density() const {
        int V = vertexCount();
        if (V <= 1) return 0.0;
        int maxEdges = directed ? V * (V - 1) : V * (V - 1) / 2;
        return static_cast<double>(edgeCount()) / maxEdges;
    }
};

int main() {
    Graph g; // unweighted graph
    cout << "Density: " << g.density() << endl; 
    return 0;
}
