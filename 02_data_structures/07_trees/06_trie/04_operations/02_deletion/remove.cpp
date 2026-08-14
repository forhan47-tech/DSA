#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool isEnd;

    Node() : isEnd(false) {}
};

class Trie {
    Node* root;

    bool eraseHelper(Node* curr, const string& word, int depth) {
        if (!curr) return false;

        if (depth == word.size()) {
            if (!curr->isEnd) return false; // Word not found
            curr->isEnd = false;
            return curr->child.empty(); // delete if no children
        }

        char ch = word[depth];
        if (!curr->child.count(ch)) return false;

        bool freeChild = eraseHelper(curr->child[ch], word, depth + 1);

        if (freeChild) {
            delete curr->child[ch];
            curr->child.erase(ch);
            return !curr->isEnd && curr->child.empty();
        }
        return false;
    }

public:
    Trie() { 
        root = new Node(); 
    }

    bool erase(const string& word) {
        return eraseHelper(root, word, 0);
    }
};

int main() {
    Trie t;
    t.erase("cat");
}
