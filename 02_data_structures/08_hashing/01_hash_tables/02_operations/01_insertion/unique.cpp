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

    int size() const {
        int total = 0;
        for (const auto &slot : table) {
            total += slot.size();
        }
        return total;
    }

    double loadFactor() const {
        return static_cast<double>(size()) / slots; 
    }

    void rehash() {
        int oldSlots = slots;
        vector<list<int>> oldTable = table;

        slots *= 2; 
        table.clear();
        table.resize(slots);

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
    }

    void insert(int val) {
        if (loadFactor() > 0.75) { 
            rehash();
        }

        int idx = hashFunction(val);
        for (int key : table[idx]) {
            if (key == val) {
                return; 
            }
        }
        table[idx].push_back(val);
    }
};

int main() {
    HashTable ht(7);
    return 0;
}
