#include <iostream>
#include <unordered_map>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    void clearGraph() {
        adj.clear();
    }
};

int main() {
    Graph g(false); // weighted graph
    return 0;
}
