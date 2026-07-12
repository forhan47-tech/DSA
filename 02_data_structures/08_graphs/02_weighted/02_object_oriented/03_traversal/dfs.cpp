#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }

    void DFSUtil(int u, unordered_set<int>& visited) const {
        visited.insert(u);
        cout << u << " ";
        for (auto& [v, w] : adj.at(u)) {
            if (!visited.count(v))
                DFSUtil(v, visited);
        }
    }

    void DFS(int start = -1) const {
        unordered_set<int> visited;
        cout << "DFS: ";

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
    Graph g(false); // weighted graph
    g.DFS(1);
    return 0;
}
