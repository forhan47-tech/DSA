#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> arr;  // underlying array
    bool isMaxHeap;   // true = max-heap, false = min-heap

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0) {
            int p = parent(i);
            if ((isMaxHeap && arr[i] > arr[p]) || (!isMaxHeap && arr[i] < arr[p])) {
                swap(arr[i], arr[p]);
                i = p;
            } else break;
        }
    }

    void heapifyDown(int i) {
        int size = arr.size();
        while (true) {
            int l = left(i), r = right(i), target = i;

            if (l < size && ((isMaxHeap && arr[l] > arr[target]) || (!isMaxHeap && arr[l] < arr[target])))
                target = l;
            if (r < size && ((isMaxHeap && arr[r] > arr[target]) || (!isMaxHeap && arr[r] < arr[target])))
                target = r;

            if (target != i) {
                swap(arr[i], arr[target]);
                i = target;
            } else break;
        }
    }

public:
    Heap(bool maxHeap = true) {
        isMaxHeap = maxHeap;
    }

    void insert(int val) {
        arr.push_back(val);
        heapifyUp(arr.size() - 1);
    }

    void removeRoot() {
        if (arr.empty()) {
            cout << "Heap is empty!\n";
            return;
        }
        arr[0] = arr.back();
        arr.pop_back();
        if (!arr.empty()) heapifyDown(0);
    }

    int getRoot() {
        if (arr.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }
        return arr[0];
    }

    void display() {
        cout << (isMaxHeap ? "Max-Heap" : "Min-Heap") << " elements: ";
        for (int val : arr) cout << val << " ";
        cout << endl;
    }
};

int main() {
    Heap maxHeap(true);  // Max-Heap
    maxHeap.insert(10);
    maxHeap.insert(40);
    maxHeap.insert(30);
    maxHeap.insert(20);

    maxHeap.display();
    cout << "Root: " << maxHeap.getRoot() << endl;

    maxHeap.removeRoot();
    maxHeap.display();

    Heap minHeap(false); // Min-Heap
    minHeap.insert(10);
    minHeap.insert(40);
    minHeap.insert(30);
    minHeap.insert(20);

    minHeap.display();
    cout << "Root: " << minHeap.getRoot() << endl;
}
