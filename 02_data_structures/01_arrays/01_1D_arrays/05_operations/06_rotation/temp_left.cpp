#include <iostream>
using namespace std;

void leftRotate(int arr[], int n, int k) {
    k = k % n; // handle larger k
    int temp[n];

    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i + k) % n];
    }

    for (int i = 0; i < n; i++) arr[i] = temp[i];
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    leftRotate(arr, 5, 2);

    cout << "Array after left rotation: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
