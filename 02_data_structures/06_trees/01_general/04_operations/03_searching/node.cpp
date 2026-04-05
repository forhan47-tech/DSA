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

    Node* search(Node* parent, int key) {
        if (!parent) return nullptr;

        if (parent->data == key) return parent;

        for (auto cld : parent->child) {
            Node* res = search(cld, key);
            if (res) return res;  
        }
        return nullptr;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    bool find(int key) {
        return search(root, key) != nullptr;
    }
};

int main() {
    GeneralTree tr;
    cout << tr.find(2) << endl;
}
