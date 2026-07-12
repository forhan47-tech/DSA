#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;
    bool isMinHeap; // true → Min Heap, false → Max Heap

    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;
    }

public:
    Heap(bool flag = false) { isMinHeap = flag; }

    bool isEmpty() { 
        return v.empty(); 
    }
};

int main() {
    Heap h;
    cout << "Is Empty? " << (h.isEmpty() ? "Yes" : "No") << endl;
}
