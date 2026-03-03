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

    int size() const {
        int total = 0;
        for (const auto &slot : table) {
            total += slot.size();
        }
        return total;
    }
};

int main() {
    HashTable ht(7);
    cout << "Size: " << ht.size() << endl;
    return 0;
}
