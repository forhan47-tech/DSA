#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;
    bool isMinHeap; // true → Min Heap, false → Max Heap

    int left(int i) { 
        return 2*i+1; 
    }

    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;
    }

public:
    Heap(bool flag = false) { 
        isMinHeap = flag; 
    }

    bool isLeaf(int i) { 
        return left(i) >= v.size(); 
    }
};

int main() {
    Heap h;
    cout << "Is Leaf? " << (h.isLeaf(0) ? "Yes" : "No") << endl;
}
