#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;
    bool isMinHeap; // true → Min Heap, false → Max Heap

    int left(int i) { 
        return 2*i+1; 
    }

    int right(int i) { 
        return 2*i+2; 
    }

    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;
    }

public:
    Heap(bool flag = false) { 
        isMinHeap = flag; 
    }

    vector<int> getChildren(int i) {
        vector<int> cld;
        if (left(i) < v.size()) cld.push_back(v[left(i)]);
        if (right(i) < v.size()) cld.push_back(v[right(i)]);
        return cld;
    }
};

int main() {
    Heap h;
    vector<int> child = h.getChildren(0);

    cout << "Children: ";
    for (int val : child) cout << val << " ";
    cout << endl;
}