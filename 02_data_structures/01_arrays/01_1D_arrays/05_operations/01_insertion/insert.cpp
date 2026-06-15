#include <iostream>
using namespace std;

void push_back(int arr[], int &n, int val) {
    arr[n] = val;
    n++;
}

void insert(int arr[], int &n, int pos, int val) {
    if (pos < 0 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == n) {
        push_back(arr, n, val);
        return;
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    insert(arr, n, 2, 10);  // index 2 -> 10
    insert(arr, n, n, 20);  // index n -> 20 (push_back)

    cout << "After insertion: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
