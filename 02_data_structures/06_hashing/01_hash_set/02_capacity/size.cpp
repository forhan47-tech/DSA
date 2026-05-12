#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashSet {
    int slots;                     
    vector<list<int>> table;                             

    int hashFunction(int val) {
        return abs(val) % slots;
    }

public:
    HashSet(int v) {
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
    HashSet hs(7);
    cout << "Size: " << hs.size() << endl;
    return 0;
}
