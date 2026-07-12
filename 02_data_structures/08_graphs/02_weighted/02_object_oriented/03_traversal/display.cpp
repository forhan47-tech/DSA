#include <iostream>
#include <unordered_map>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    void printGraph() const {
        cout << "Adjacency List (Weighted):\n";
        for (auto& pair : adj) {
            cout << pair.first << ": ";
            for (auto& [v, w] : pair.second)
                cout << "(" << v << ", w=" << w << ") ";
            cout << endl;
        }
    }
};

int main() {
    Graph g(false); // weighted graph
    g.printGraph();
    return 0;
}
