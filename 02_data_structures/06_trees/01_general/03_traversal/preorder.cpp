#include <iostream>
#include <vector>
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

    void preorder(Node* curr) {
        if (!curr) return;

        cout << curr->data << " ";
        for (auto cld : curr->child) 
            preorder(cld);
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    void dfs() { 
        cout << "DFS: "; 
        preorder(root); 
        cout << endl; 
    }
};

int main() {
    GeneralTree tr;
}
