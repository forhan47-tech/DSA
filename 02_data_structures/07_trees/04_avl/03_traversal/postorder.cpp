#include <iostream>
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

    void postorder(Node* curr) {
        if (!curr) return;
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << " ";
    }

public:
    AVL() {
        root = nullptr;
    }

    void dfs(){ 
        cout << "Postorder: "; 
        postorder(root); 
        cout << endl; 
    }
};

int main() {
    AVL avl;
    avl.dfs(); 
}
