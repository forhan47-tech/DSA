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

    // Search for a word
    bool search(const string& word) {
        Node* current = root;
        for (char ch : word) {
            if (!current->children[ch]) return false;
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }
};

// Demo
int main() {
    Trie trie;
    cout << "Search 'cat': " << trie.search("cat") << endl;
    cout << "Search 'cap': " << trie.search("cap") << endl;
    return 0;
}
