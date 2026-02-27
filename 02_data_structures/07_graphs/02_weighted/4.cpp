#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// Edge structure with weight
struct Edge {
    int dest;
    int weight;
};

class WeightedGraph {
    int V;
    bool isDirected;
    vector<list<Edge>> adj;

    void DFSUtil(int u, vector<bool>& visited) const {
        visited[u] = true;
        cout << u << " ";
        for (auto &edge : adj[u]) {
            if (!visited[edge.dest]) DFSUtil(edge.dest, visited);
        }
    }

public:
    // Constructor
    WeightedGraph(int V = 0, bool directed = false) : V(V), isDirected(directed), adj(V) {}

    // STL-like methods
    bool empty() const { return V == 0; }
    int size() const { return V; }

    // Insertion
    int addVertex() {
        adj.push_back(list<Edge>());
        return V++;
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        if (!isDirected) adj[v].push_back({u, w});
    }

    // Deletion
    void removeEdge(int u, int v) {
        adj[u].remove_if([&](const Edge& e){ return e.dest == v; });
        if (!isDirected) adj[v].remove_if([&](const Edge& e){ return e.dest == u; });
    }

    void removeVertex(int u) {
        if (u >= V) return;
        for (int i = 0; i < V; i++) adj[i].remove_if([&](const Edge& e){ return e.dest == u; });
        adj[u].clear();
    }

    // Searching
    bool hasEdge(int u, int v) const {
        return any_of(adj[u].begin(), adj[u].end(), [&](const Edge& e){ return e.dest == v; });
    }

    // Counting
    int countVertices() const { return V; }

    int countEdges() const {
        int total = 0;
        for (int i = 0; i < V; i++) total += adj[i].size();
        return isDirected ? total : total / 2;
    }

    int degree(int u) const { return adj[u].size(); }

    // Traversal
    void BFS(int start) const {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (auto &edge : adj[u]) {
                if (!visited[edge.dest]) {
                    visited[edge.dest] = true;
                    q.push(edge.dest);
                }
            }
        }
    }

    void DFS(int start) const {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    // Dijkstra’s shortest path
    void dijkstra(int src) const {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        using P = pair<int,int>; // (distance, vertex)
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &edge : adj[u]) {
                int v = edge.dest;
                int w = edge.weight;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            if (dist[i] == INT_MAX) cout << "INF";
            else cout << dist[i];
            cout << endl;
        }
    }

    // Print adjacency list
    void printGraph() const {
        cout << (isDirected ? "Directed Weighted Graph\n" : "Undirected Weighted Graph\n");
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (auto &edge : adj[i]) cout << "(" << edge.dest << ", w=" << edge.weight << ") ";
            cout << endl;
        }
    }
};
