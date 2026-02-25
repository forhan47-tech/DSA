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

    void dfsHelper(Node* curr) {
        if (!curr) 
            return;

        cout << curr->data << " ";
        for (auto ch : curr->child) 
            dfsHelper(ch);
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    void dfs() { 
        cout << "DFS: "; 
        dfsHelper(root); 
        cout << endl; 
    }
};

int main() {
    GeneralTree tr;
    tr.dfs();
}
