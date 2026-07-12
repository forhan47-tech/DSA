#include <iostream>
#include <unordered_map>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }

    int degree(int v) const {
        if (!hasVertex(v)) return -1;
        return adj.at(v).size();
    }
};

int main() {
    Graph g(false); // weighted graph
    cout << "Degree of 4: " << g.degree(4) << endl;
    return 0;
}
