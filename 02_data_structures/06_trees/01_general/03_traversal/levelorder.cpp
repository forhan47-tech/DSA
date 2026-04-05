#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> child;

    Node(int val) {
        data = val;
    }
};

class GeneralTree {
    Node* root;

    void levelOrder(Node* parent) {
        if (!parent) return;

        queue<Node*> q;
        q.push(parent);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";
            for (auto cld : curr->child) {
                q.push(cld);
            }
        }
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    void bfs() { 
        cout << "BFS: "; 
        levelOrder(root); 
        cout << endl; 
    }
};

int main() {
    GeneralTree tr;
}
