#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class GeneralTree {
    vector<int> parent;              
    vector<vector<int>> children;    
    vector<bool> deleted;            

public:
    GeneralTree(int n) {
        parent.resize(n, -1);
        children.resize(n);
        deleted.resize(n, false);
    }

    void addEdge(int p, int c) {
        parent[c] = p;
        children[p].push_back(c);
    }

    // DFS search: returns index if found, -1 otherwise
    int searchDFS(int node, int target) {
        if (deleted[node]) return -1;
        if (node == target) return node;
        for (int child : children[node]) {
            int result = searchDFS(child, target);
            if (result != -1) return result;
        }
        return -1;
    }

    // BFS search: returns index if found, -1 otherwise
    int searchBFS(int root, int target) {
        if (deleted[root]) return -1;
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (deleted[current]) continue;
            if (current == target) return current;
            for (int child : children[current]) {
                if (!deleted[child]) q.push(child);
            }
        }
        return -1;
    }
};

int main() {
    GeneralTree tree(6); // nodes: 0..5
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(1, 3);
    tree.addEdge(1, 4);
    tree.addEdge(2, 5);

    int dfsResult = tree.searchDFS(0, 4);
    cout << "DFS search for 4: " << (dfsResult != -1 ? "Found at index " + to_string(dfsResult) : "Not Found") << endl;

    int bfsResult = tree.searchBFS(0, 5);
    cout << "BFS search for 5: " << (bfsResult != -1 ? "Found at index " + to_string(bfsResult) : "Not Found") << endl;

    int notFound = tree.searchDFS(0, 6);
    cout << "DFS search for 6: " << (notFound != -1 ? "Found" : "Not Found") << endl;

    return 0;
}
