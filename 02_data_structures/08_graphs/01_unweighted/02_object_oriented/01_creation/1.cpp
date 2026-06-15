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

    // ---------------- Insertion ----------------
    void addVertex(int v) {
        if (!hasVertex(v))
            adj[v] = unordered_set<int>();
    }

    void addEdge(int u, int v) {
        addVertex(u);
        addVertex(v);
        adj[u].insert(v);
        if (!directed) adj[v].insert(u);
    }

    // ---------------- Deletion ----------------
    void removeEdge(int u, int v) {
        if (!hasVertex(u) || !hasVertex(v)) return;
        adj[u].erase(v);
        if (!directed) adj[v].erase(u);
    }

    void removeVertex(int v) {
        if (!hasVertex(v)) return;
        adj.erase(v);
        for (auto& pair : adj) {
            pair.second.erase(v);
        }
    }

    // ---------------- Searching ----------------
    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }

    bool hasEdge(int u, int v) const {
        if (!hasVertex(u)) return false;
        return adj.at(u).find(v) != adj.at(u).end();
    }

    // ---------------- Traversal ----------------
    void BFSUtil(int start, unordered_set<int>& visited) const {
        queue<int> q;
        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (int v : adj.at(u)) {
                if (!visited.count(v)) {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
    }

    void BFS(int start = -1) const {
        unordered_set<int> visited;
        cout << "BFS:\n";

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

    // ---------------- Properties ----------------
    int vertexCount() const { return adj.size(); }

    int edgeCount() const {
        int count = 0;
        for (auto& pair : adj) count += pair.second.size();
        return directed ? count : count / 2;
    }

    int degree(int v) const {
        if (!hasVertex(v)) return -1;
        return adj.at(v).size();
    }

    bool isEmpty() const { return adj.empty(); }

    double density() const {
        int V = vertexCount();
        if (V <= 1) return 0.0;
        int maxEdges = directed ? V * (V - 1) : V * (V - 1) / 2;
        return static_cast<double>(edgeCount()) / maxEdges;
    }

    // ---------------- Path Existence ----------------
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

    // ---------------- Display ----------------
    void printGraph() const {
        cout << "Adjacency List:\n";
        for (auto& pair : adj) {
            cout << pair.first << ": ";
            for (int v : pair.second) cout << v << " ";
            cout << endl;
        }
    }

    // ---------------- Utility ----------------
    void clearGraph() {
        adj.clear();
    }
};

int main() {
    Graph g; // unweighted graph

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(6, 7);

    cout << "Graph:\n";
    g.printGraph();

    g.BFS(2);
    g.DFS(4);

    cout << "Search vertex 3? " << (g.hasVertex(3) ? "Yes" : "No") << endl;
    cout << "Search edge (2->3)? " << (g.hasEdge(2,3) ? "Yes" : "No") << endl;

    cout << "Vertices: " << g.vertexCount() << endl;
    cout << "Edges: " << g.edgeCount() << endl;
    cout << "Density: " << g.density() << endl; 
    cout << "Degree of 4: " << g.degree(4) << endl;
    cout << "Graph empty? " << (g.isEmpty() ? "Yes" : "No") << endl;
    cout << "Path exists between (1->5)? " << (g.hasPath(1,5) ? "Yes" : "No") << endl;
    return 0;
}
