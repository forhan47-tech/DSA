#include <iostream>
using namespace std;

void pop_back(int arr[], int &n) {
    if (n <= 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    n--;
}

void remove(int arr[], int &n, int pos) {
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == n - 1) {
        pop_back(arr, n);
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    remove(arr, n, 2); // index 2 -> remove 3
    remove(arr, n, n - 1); // last index -> remove 5

    cout << "After deletion: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
