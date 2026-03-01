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
        if (!parent) {
            return nullptr;
        }

        if (parent->data == key) {
            return parent;
        }

        for (auto cld : parent->child) {
            Node* res = search(cld, key);
            if (res) {
                return res;  
            }
        }
        return nullptr;
    }


public:
    GeneralTree() {
        root = nullptr;
    }

    void link(int p, int c) {
        if (!root) {
            root = new Node(p);
            root->child.push_back(new Node(c));
            return;
        }

        Node* parent = search(root, p);
        if (parent) {
            parent->child.push_back(new Node(c));
        }
    }
};

int main() {
    GeneralTree tr;
}