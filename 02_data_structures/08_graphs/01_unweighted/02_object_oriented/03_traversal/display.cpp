#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    // ---------------- Searching ----------------
    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }

    void printGraph() const {
        cout << "Adjacency List:\n";
        for (auto& pair : adj) {
            cout << pair.first << ": ";
            for (int v : pair.second) cout << v << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g; // unweighted graph

    cout << "Graph:\n";
    g.printGraph();

    return 0;
}
