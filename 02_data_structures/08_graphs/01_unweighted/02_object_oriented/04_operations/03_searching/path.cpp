#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }

    bool hasPath(int src, int dest) const {
        if (!hasVertex(src) || !hasVertex(dest)) return false;

        unordered_set<int> visited;
        queue<int> q;
        q.push(src);
        visited.insert(src);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == dest) return true;
            for (int v : adj.at(u)) {
                if (!visited.count(v)) {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g; // unweighted graph
    cout << "Path exists between (1->5)? " << (g.hasPath(1,5) ? "Yes" : "No") << endl;
    return 0;
}
