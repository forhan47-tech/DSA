#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Edge node
struct EdgeNode {
    int dest;            // destination vertex
    EdgeNode* next;      // pointer to next edge
};

// Vertex node
struct VertexNode {
    int id;              // vertex id
    EdgeNode* edges;     // head of edge list
    VertexNode* next;    // pointer to next vertex
};

// Graph structure
struct Graph {
    VertexNode* vertices; // head of vertex list

    Graph() : vertices(nullptr) {}

    // Add vertex
    void addVertex(int id) {
        if (hasVertex(id)) return; // avoid duplicates
        VertexNode* v = new VertexNode{id, nullptr, vertices};
        vertices = v;
    }

    // Find vertex
    VertexNode* findVertex(int id) {
        VertexNode* curr = vertices;
        while (curr) {
            if (curr->id == id) return curr;
            curr = curr->next;
        }
        return nullptr;
    }

    // Add edge
    void addEdge(int src, int dest) {
        VertexNode* v = findVertex(src);
        if (!v) return;
        EdgeNode* e = new EdgeNode{dest, v->edges};
        v->edges = e;
    }

    // Remove edge
    void removeEdge(int src, int dest) {
        VertexNode* v = findVertex(src);
        if (!v) return;
        EdgeNode* curr = v->edges;
        EdgeNode* prev = nullptr;
        while (curr) {
            if (curr->dest == dest) {
                if (prev) prev->next = curr->next;
                else v->edges = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Remove vertex
    void removeVertex(int id) {
        // Remove edges pointing to this vertex
        VertexNode* v = vertices;
        while (v) {
            removeEdge(v->id, id);
            v = v->next;
        }

        // Remove the vertex itself
        VertexNode* curr = vertices;
        VertexNode* prev = nullptr;
        while (curr) {
            if (curr->id == id) {
                EdgeNode* e = curr->edges;
                while (e) {
                    EdgeNode* temp = e;
                    e = e->next;
                    delete temp;
                }
                if (prev) prev->next = curr->next;
                else vertices = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Searching
    bool hasVertex(int id) {
        return findVertex(id) != nullptr;
    }

    bool hasEdge(int src, int dest) {
        VertexNode* v = findVertex(src);
        if (!v) return false;
        EdgeNode* e = v->edges;
        while (e) {
            if (e->dest == dest) return true;
            e = e->next;
        }
        return false;
    }

    // Counting
    int countVertices() {
        int total = 0;
        VertexNode* v = vertices;
        while (v) {
            total++;
            v = v->next;
        }
        return total;
    }

    int countEdges(bool directed = false) {
        int total = 0;
        VertexNode* v = vertices;
        while (v) {
            EdgeNode* e = v->edges;
            while (e) {
                total++;
                e = e->next;
            }
            v = v->next;
        }
        return directed ? total : total / 2;
    }

    int degree(int id) {
        VertexNode* v = findVertex(id);
        if (!v) return 0;
        int total = 0;
        EdgeNode* e = v->edges;
        while (e) {
            total++;
            e = e->next;
        }
        return total;
    }

    // Traversal
    void BFS(int start) {
        unordered_map<int, bool> visited;
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            VertexNode* v = findVertex(u);
            if (!v) continue;
            EdgeNode* e = v->edges;
            while (e) {
                if (!visited[e->dest]) {
                    visited[e->dest] = true;
                    q.push(e->dest);
                }
                e = e->next;
            }
        }
    }

    void DFSUtil(int u, unordered_map<int,bool>& visited) {
        visited[u] = true;
        cout << u << " ";
        VertexNode* v = findVertex(u);
        if (!v) return;
        EdgeNode* e = v->edges;
        while (e) {
            if (!visited[e->dest]) DFSUtil(e->dest, visited);
            e = e->next;
        }
    }

    void DFS(int start) {
        unordered_map<int,bool> visited;
        DFSUtil(start, visited);
    }

    // Print graph
    void printGraph() {
        VertexNode* v = vertices;
        while (v) {
            cout << "Vertex " << v->id << ": ";
            EdgeNode* e = v->edges;
            while (e) {
                cout << e->dest << " ";
                e = e->next;
            }
            cout << endl;
            v = v->next;
        }
    }
};
