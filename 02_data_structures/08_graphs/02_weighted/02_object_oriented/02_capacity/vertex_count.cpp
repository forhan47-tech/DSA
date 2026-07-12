#include <iostream>
#include <unordered_map>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    int vertexCount() const { 
        return adj.size(); 
    }
};

int main() {
    Graph g(false); // weighted graph
    cout << "Vertices: " << g.vertexCount() << endl;
    return 0;
}
