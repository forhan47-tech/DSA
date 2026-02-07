#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = size(arr);
    int pos = 2; // index to delete

    for(int i = pos; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;

    cout << "After deletion: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
