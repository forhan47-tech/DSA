#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }

    void BFSUtil(int start, unordered_set<int>& visited) const {
        queue<int> q;
        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (auto& [v, w] : adj.at(u)) {
                if (!visited.count(v)) {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
    }

    void BFS(int start = -1) const {
        unordered_set<int> visited;
        cout << "BFS: ";

        if (start != -1 && hasVertex(start) && !visited.count(start)) {
            BFSUtil(start, visited);
            cout << endl;
        }

        for (auto& pair : adj) {
            if (!visited.count(pair.first)) {
                BFSUtil(pair.first, visited);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g(false); // weighted graph
    g.BFS(1);
    return 0;
}
