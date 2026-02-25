#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool isEndOfWord;

    Node() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    Node* root;

    void dfsTraversal(Node* node, string prefix) {
    if (node->isEndOfWord) {
        cout << prefix << endl;
    }
    for (auto& pair : node->children) {
        dfsTraversal(pair.second, prefix + pair.first);
    }
}

public:
    Trie() { 
        root = new Node(); 
    }

    void printAllWords() {
    dfsTraversal(root, "");
}

};

int main() {
    Trie trie;
}
