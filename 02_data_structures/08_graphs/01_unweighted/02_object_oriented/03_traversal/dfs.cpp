#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }

    void DFSUtil(int u, unordered_set<int>& visited) const {
        visited.insert(u);
        cout << u << " ";
        for (int v : adj.at(u)) {
            if (!visited.count(v))
                DFSUtil(v, visited);
        }
    }

    void DFS(int start = -1) const {
        unordered_set<int> visited;
        cout << "DFS:\n";

        if (start != -1 && hasVertex(start) && !visited.count(start)) {
            DFSUtil(start, visited);
            cout << endl;
        }

        for (auto& pair : adj) {
            if (!visited.count(pair.first)) {
                DFSUtil(pair.first, visited);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g; // unweighted graph
    g.DFS(4);
    return 0;
}
