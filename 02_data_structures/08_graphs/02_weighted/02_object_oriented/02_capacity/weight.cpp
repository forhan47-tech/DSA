#include <iostream>
#include <unordered_map>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    int totalWeight() const {
        int sum = 0;
        for (auto& pair : adj) {
            for (auto& [v, w] : pair.second) {
                sum += w;
            }
        }
        return directed ? sum : sum / 2;
    }
};

int main() {
    Graph g(false); // weighted graph
    cout << "Total weight: " << g.totalWeight() << endl;
    return 0;
}
