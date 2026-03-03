#include <iostream>
#include <vector>
#include <list>
#include <queue>      
#include <functional> 
#include <climits>    
using namespace std;

class Edge {
public:
    int dest;
    int weight;
};

class WeightedGraph {
    int V;
    bool isDirected;
    vector<list<Edge>> adj;

public:
    WeightedGraph(int V = 0, bool directed = false) {
        this->V = V; 
        isDirected = directed;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cerr << "Invalid vertex index\n";
            return;
        }
        adj[u].push_back({v, w});
        if (!isDirected) {
            adj[v].push_back({u, w});
        }
    }

    void dijkstra(int src) const {
        if (src < 0 || src >= V) {
            cerr << "Invalid source vertex\n";
            return;
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        using P = pair<int,int>; 
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
};

int main() {
    WeightedGraph wg(5, false); 

    wg.addEdge(0, 1, 2);
    wg.addEdge(0, 2, 4);
    wg.addEdge(1, 2, 1);
    wg.addEdge(1, 3, 7);
    wg.addEdge(2, 4, 3);

    wg.dijkstra(0); 
}
