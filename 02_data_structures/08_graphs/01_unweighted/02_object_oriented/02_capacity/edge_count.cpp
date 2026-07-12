#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
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
    Graph g; // unweighted graph
    cout << "Edges: " << g.edgeCount() << endl;
    return 0;
}
