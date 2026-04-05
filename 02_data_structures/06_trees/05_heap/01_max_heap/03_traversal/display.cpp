#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

public:
    void display() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap mh;
}
