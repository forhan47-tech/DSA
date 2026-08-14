#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool isEnd;

    Node() {
        isEnd = false;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node(); 
    }

    bool empty() {
        return root->child.empty() && !root->isEnd;
    }
};

int main() {
    Trie t;
    cout << "Is Empty? " << (t.empty() ? "Yes" : "No") << endl;
}
