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

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }
};

int main() {
    Graph g(false); // weighted graph
    g.addVertex(4);
    return 0;
}