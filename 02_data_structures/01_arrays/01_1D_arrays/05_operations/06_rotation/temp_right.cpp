#include <iostream>
using namespace std;

void rightRotate(int arr[], int n, int k) {
    k = k % n;
    int temp[n];

    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    for (int i = 0; i < n; i++) arr[i] = temp[i];
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    rightRotate(arr, 5, 2);

    cout << "Array after right rotation: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
