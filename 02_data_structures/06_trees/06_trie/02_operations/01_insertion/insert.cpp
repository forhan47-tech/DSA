#include <iostream>
#include <unordered_map>
#include <string>
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

public:
    Trie() { 
        root = new Node(); 
    }

    void insert(const string& word) {
        Node* current = root;
        for (char ch : word) {
            if (!current->children[ch]) {
                current->children[ch] = new Node();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }
};

// Demo
int main() {
    Trie trie;
    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");
}
