#include <iostream>
#include <unordered_map>
#include <queue>
#include <limits>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj;

public:
    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
    }

    // Dijkstra’s Algorithm
    void dijkstra(int src) {
        unordered_map<int,int> dist;
        for (auto &p : adj) dist[p.first] = numeric_limits<int>::max();
        dist[src] = 0;

        using P = pair<int,int>; // (distance, vertex)
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if (d > dist[u]) continue;

            for (auto &e : adj[u]) {
                int v = e.first, w = e.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from " << src << ":\n";
        for (auto &p : dist) {
            cout << p.first << " -> " << p.second << endl;
        }
    }
};

int main() {
    Graph g;

    g.addEdge(0,1,4);
    g.addEdge(0,2,1);
    g.addEdge(1,2,2);
    g.addEdge(1,3,5);
    g.addEdge(2,3,8);   

    g.dijkstra(0);
}
