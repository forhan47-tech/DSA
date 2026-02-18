#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = size(arr);
    int pos = n-1; // index to delete

    if(pos < 0 || pos >= n) {
        cout << "Invalid position!";
        return 0;
    }

    if(pos == n-1) {
        n--;
    }

    cout << "After deletion: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
