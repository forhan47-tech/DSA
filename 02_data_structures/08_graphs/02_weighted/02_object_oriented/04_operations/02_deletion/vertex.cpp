#include <iostream>
#include <unordered_map>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
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
    Graph g(false); // weighted graph
    return 0;
}
