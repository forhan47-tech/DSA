#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int slots;                      
    vector<list<int>> table;         
    int count;                      

    int hashFunction(int val) {
        return abs(val) % slots;
    }

public:
    HashTable(int v) {
        slots = v;
        table.resize(v);
        count = 0;
    }

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
