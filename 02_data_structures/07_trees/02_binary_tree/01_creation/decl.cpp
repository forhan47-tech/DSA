#include <iostream>
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
};

int main() {
    BinaryTree bt;
}
