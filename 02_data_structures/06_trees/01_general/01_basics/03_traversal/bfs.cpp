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

    void levelOrder(Node* root) {
        if (!root) 
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            for (auto ch : curr->child) 
                q.push(ch);
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
    tr.bfs();
}
