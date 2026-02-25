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

    bool searchBFS(Node* root, int key) {
    if (!root) 
        return false;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->data == key) 
            return true;

        for (auto ch : curr->child) {
            q.push(ch);
        }
    }
    return false;
}

public:
    GeneralTree() {
        root = nullptr;
    }

    bool search(int key) { 
        return searchBFS(root, key); 
    }
};

int main() {
    GeneralTree tr;
}
