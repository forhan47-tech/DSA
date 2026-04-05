#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = size(arr);
    
    int pos = n; // index to insert
    int val = 99;

    if(pos < 0 || pos > n) {
        cout << "Invalid position!";
        return 0;
    }

    if(pos == n) {
        arr[pos] = val; // insert at end
        n++;
    }

    cout << "After insertion: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
