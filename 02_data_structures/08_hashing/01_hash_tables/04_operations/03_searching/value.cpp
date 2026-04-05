#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int slots;                      
    vector<list<int>> table;         

    int hashFunction(int value) {
        return abs(value) % slots;
    }

public:
    HashTable(int v) {
        slots = v;
        table.resize(v);
    }

    bool search(int val) {
        int idx = hashFunction(val);
        for (int key : table[idx]) {
            if (key == val) {
                return true;   
            }
        }
        return false;         
    }
};

int main() {
    HashTable ht(7);
    return 0;
}
