#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 4, 5};
    int n = size(arr);

    int pos = 2; // index where to insert
    int val = 3;

    for(int i = n; i > pos; i--) {
        arr[i] = arr[i-1]; // shift right
    }
    arr[pos] = val;
    n++;

    cout << "After insertion at position 2: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
