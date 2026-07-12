#include <iostream>
#include <unordered_map>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }

    bool hasEdge(int u, int v) const {
        if (!hasVertex(u)) return false;
        return adj.at(u).find(v) != adj.at(u).end();
    }
};

int main() {
    Graph g(false); // weighted graph
    return 0;
}
