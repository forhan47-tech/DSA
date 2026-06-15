#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; // Insert key at correct position
    }
}

int main() {
    int arr[6] = {5, 2, 9, 1, 5, 6};
    insertionSort(arr, 6);

    cout << "Sorted Array: ";
    for (int i = 0; i < 6; i++) cout << arr[i] << " ";
}
