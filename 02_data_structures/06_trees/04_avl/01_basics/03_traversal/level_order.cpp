#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
    Node* root;

    void levelOrder(Node* node) {
    if (!node) return;
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

public:
    AVL() {
        root = nullptr;
    }

    void bfs(){ 
        cout << "Level Order: "; 
        levelOrder(root); 
        cout << endl; 
    }
};

int main() {
    AVL tree;
}
