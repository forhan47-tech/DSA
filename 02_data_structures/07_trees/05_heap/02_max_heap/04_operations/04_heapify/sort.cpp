#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyDown(int i) {
        int largest = i;
        int l = left(i), r = right(i);

        if (l < heap.size() && heap[l] > heap[largest]) largest = l;
        if (r < heap.size() && heap[r] > heap[largest]) largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void buildHeap(vector<int>& arr) { 
        heap = arr; 
        for (int i = heap.size()/2 - 1; i >= 0; i--) { 
            heapifyDown(i); 
        } 
    }
};

int main() {
    MaxHeap mh;
}
