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

    void levelOrder(Node* curr) {
        if (!curr) return;
        queue<Node*> q;
        q.push(curr);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
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
    AVL avl;
    avl.bfs();
}
