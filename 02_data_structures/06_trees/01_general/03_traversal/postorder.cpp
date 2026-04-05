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

    void postorder(Node* curr) {
        if (!curr) return;

        for (auto cld : curr->child) {
            postorder(cld);
        }
        cout << curr->data << " ";
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    void dfs() { 
        cout << "DFS: "; 
        postorder(root); 
        cout << endl; 
    }
};

int main() {
    GeneralTree tr;
}
