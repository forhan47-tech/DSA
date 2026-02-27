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

    double loadFactor() {
        return (double)count / slots;
    }

    void rehash() {
        int oldSlots = slots;
        vector<list<int>> oldTable = table;

        slots *= 2; 
        table.clear();
        table.resize(slots);
        count = 0;

        for (int i = 0; i < oldSlots; i++) {
            for (int val : oldTable[i]) {
                insert(val);
            }
        }
    }

public:
    HashTable(int v) {
        slots = v;
        table.resize(v);
        count = 0;
    }

    void insert(int val) {
        if (loadFactor() > 0.75) { 
            rehash();
        }
        int idx = hashFunction(val);
        table[idx].push_back(val);
        count++;
    }
};

int main() {
    HashTable ht(7);
}
