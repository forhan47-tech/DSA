#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int slots;                      
    vector<list<int>> table;       

    int hashFunction(int val) {
        return abs(val) % slots;   
    }

public:
    HashTable(int v) {
        slots = v;
        table.resize(v);
    }

    void clear() {
        for (auto &slot : table) {
            slot.clear();       
        }
    }
};

int main() {
    HashTable ht(7);
    ht.clear(); 
    return 0;
}
