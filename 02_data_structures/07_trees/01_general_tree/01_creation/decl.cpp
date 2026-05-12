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

public:
    GeneralTree() {
        root = nullptr;
    }
};

int main() {
    GeneralTree tr;
}
