#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    void clearGraph() {
        adj.clear();
    }
};

int main() {
    Graph g; // unweighted graph
    g.clearGraph();
    return 0;
}
