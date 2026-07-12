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

    void heapifyUp(int i) {
        if (i > 0 && compare(v[i], v[parent(i)])) {
            swap(v[i], v[parent(i)]);
            heapifyUp(parent(i));
        }
    }

public:
    Heap(bool flag = false) { 
        isMinHeap = flag; 
    }

    void push(int val) {
        v.push_back(val);
        heapifyUp(v.size()-1);
    }
};

int main() {
    Heap h;
    h.push(10);
    h.push(5);
    h.push(20);
    h.push(3);
}
