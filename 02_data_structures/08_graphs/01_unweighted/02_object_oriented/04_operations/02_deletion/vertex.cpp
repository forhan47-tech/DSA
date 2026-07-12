#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    void removeVertex(int v) {
        if (!hasVertex(v)) return;
        adj.erase(v);
        for (auto& pair : adj) {
            pair.second.erase(v);
        }
    }

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }

};

int main() {
    Graph g; // unweighted graph
    g.removeVertex(4);
    return 0;
}
