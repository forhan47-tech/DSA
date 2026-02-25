#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool isEndOfWord;
    Node() { isEndOfWord = false; }
};

class Trie {
    Node* root;

    void deleteTrieHelper(Node* node) {
        if (!node) return;
        for (auto& pair : node->children) {
            deleteTrieHelper(pair.second);
        }
        delete node;
    }

public:
    Trie() { 
        root = new Node(); 
    }

    void deleteTrie() {
        deleteTrieHelper(root);
        root = nullptr; // reset root
    }
};

int main() {
    Trie trie;
}
