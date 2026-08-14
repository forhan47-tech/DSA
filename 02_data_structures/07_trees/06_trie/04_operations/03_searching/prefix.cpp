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
private:
    Node* root;

public:
    Trie() { 
        root = new Node(); 
    }

    bool startsWith(const string& pfx) { 
        Node* curr = root; 
        for (char ch : pfx) { 
            if (!curr->child.count(ch)) return false;
            curr = curr->child[ch]; 
        } 
        return true;
    }
};

int main() {
    Trie t;
    cout << "Starts with(cat): " << (t.startsWith("cat") ? "Yes" : "No") << endl;
}
