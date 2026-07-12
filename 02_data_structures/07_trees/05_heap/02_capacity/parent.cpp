#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;
    bool isMinHeap; // true → Min Heap, false → Max Heap

    int parent(int i) { 
        return (i-1)/2; 
    }

    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;
    }

public:
    Heap(bool flag = false) { 
        isMinHeap = flag; 
    }

    int getParent(int i) { 
        return (i > 0) ? v[parent(i)] : -1; 
    }
};

int main() {
    Heap h;
    cout << "Parent of index 0: " << h.getParent(0) << endl;
    return 0;
}
