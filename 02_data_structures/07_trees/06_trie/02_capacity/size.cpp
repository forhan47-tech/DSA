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

    int countWords(Node* curr) {
        if (!curr) return 0;
        int count = curr->isEnd ? 1 : 0;
        for (auto& [ch, next] : curr->child) {
            count += countWords(next);
        }
        return count;
    }

public:
    Trie() { 
        root = new Node();
    }

    int size() {
        return countWords(root);
    }
};

int main() {
    Trie t;
    cout << "Trie size: " << t.size() << endl;
}
