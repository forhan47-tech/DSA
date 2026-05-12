#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
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
    MinHeap mh;
}
