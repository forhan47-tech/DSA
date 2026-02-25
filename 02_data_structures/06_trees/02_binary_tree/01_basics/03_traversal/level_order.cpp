#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void levelOrder() {
        if (!root) 
            return;

        cout << "Level Order: ";
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left) 
                q.push(curr->left);
            
            if (curr->right) 
                q.push(curr->right);
        }     
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
    bt.levelOrder();
}
