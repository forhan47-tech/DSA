#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    // ---------------- Insertion ----------------
    void addVertex(int v) {
        if (!hasVertex(v))
            adj[v] = unordered_map<int,int>();
    }

    void addEdge(int u, int v, int w) {
        addVertex(u);
        addVertex(v);
        adj[u][v] = w;
        if (!directed) adj[v][u] = w;
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

    int totalWeight() const {
        int sum = 0;
        for (auto& pair : adj) {
            for (auto& [v, w] : pair.second) {
                sum += w;
            }
        }
        return directed ? sum : sum / 2;
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
            for (auto& [v, w] : adj.at(u)) {
                if (!visited.count(v)) {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
        return false;
    }

    // ---------------- Shortest Path (Dijkstra) ----------------
    void dijkstra(int src) const {
        if (!hasVertex(src)) return;

        unordered_map<int, int> dist;
        for (auto& pair : adj) dist[pair.first] = numeric_limits<int>::max();
        dist[src] = 0;

        using P = pair<int,int>; // (distance, vertex)
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto& [v, w] : adj.at(u)) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from " << src << ":\n";
        for (auto& [v, d] : dist) {
            cout << v << " : ";
            if (d == numeric_limits<int>::max()) cout << "INF";
            else cout << d;
            cout << endl;
        }
    }

    // ---------------- Display ----------------
    void printGraph() const {
        cout << "Adjacency List (Weighted):\n";
        for (auto& pair : adj) {
            cout << pair.first << ": ";
            for (auto& [v, w] : pair.second)
                cout << "(" << v << ", w=" << w << ") ";
            cout << endl;
        }
    }

    // ---------------- Utility ----------------
    void clearGraph() {
        adj.clear();
    }
};

int main() {
    Graph g(false); // weighted graph

    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 3);

    g.printGraph();

    g.BFS(1);
    g.DFS(1);

    cout << "Density: " << g.density() << endl;
    cout << "Total weight: " << g.totalWeight() << endl;
    cout << "Vertices: " << g.vertexCount() << endl;
    cout << "Edges: " << g.edgeCount() << endl;
    cout << "Degree of 4: " << g.degree(4) << endl;
    cout << "Density: " << g.density() << endl;
    
    g.dijkstra(1);

    return 0;
}
