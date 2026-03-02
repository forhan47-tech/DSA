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

    bool attach(Node* curr, int parent, int child) {
        if (!curr) return false;

        if (curr->data == parent) {
            curr->child.push_back(new Node(child));
            return true;
        }

        for (auto cld : curr->child) {
            if (attach(cld, parent, child)) return true;
        }
        return false;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    void link(int p, int c) {
        if (!root) {
            root = new Node(p);
            root->child.push_back(new Node(c));
        } else {
            if (!attach(root, p, c)) {
                cout << "Parent " << p << " not found!" << endl;
            }
        }
    }
};

int main() {
    GeneralTree tr;
    tr.link(1, 2); 
    tr.link(1, 3);  
    tr.link(5, 6);  
}
