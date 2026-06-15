#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    int parent(int i) { 
        return (i - 1) / 2; 
    }
    
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
};

int main() {
    MaxHeap mh;
}
