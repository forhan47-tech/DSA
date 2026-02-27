#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int slots;  
    vector<list<pair<int, string>>> table;  
    int count;  // track number of elements

    int hashFunction(int key) {
        return key % slots;
    }

public:
    HashTable(int v) {
        slots = v;
        table.resize(v);
        count = 0;
    }

    // Remove by key
    void remove(int key) {
        int idx = hashFunction(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (it->first == key) {
                table[idx].erase(it);
                count--;
                return;
            }
        }
    }
};

int main() {
    HashTable ht(7);
    return 0;
}
