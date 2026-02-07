#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = size(arr); // current size
    int val = 99;

    arr[n] = val; // insert at end
    n++;

    cout << "After insertion at end: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
