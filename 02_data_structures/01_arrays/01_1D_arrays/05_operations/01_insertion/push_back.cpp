#include <iostream>
using namespace std;

void push_back(int arr[], int &n, int val) {
    arr[n] = val;
    n++;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    push_back(arr, n, 10); // index 5 -> add 10
    push_back(arr, n, 20); // index 6 -> add 20

    cout << "After insertion: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
