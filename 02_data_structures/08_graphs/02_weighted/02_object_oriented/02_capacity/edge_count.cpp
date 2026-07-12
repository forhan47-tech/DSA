#include <iostream>
#include <unordered_map>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    int edgeCount() const {
        int count = 0;
        for (auto& pair : adj) count += pair.second.size();
        return directed ? count : count / 2;
    }
};

int main() {
    Graph g(false); // weighted graph
    cout << "Edges: " << g.edgeCount() << endl;
    return 0;
}
