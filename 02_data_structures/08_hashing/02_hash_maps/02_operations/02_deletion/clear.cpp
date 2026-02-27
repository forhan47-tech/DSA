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

    // Clear the entire table
    void clear() {
        for (int i = 0; i < slots; i++) {
            table[i].clear();
        }
        count = 0;
    }
};

int main() {
    HashTable ht(7);
    return 0;
}
