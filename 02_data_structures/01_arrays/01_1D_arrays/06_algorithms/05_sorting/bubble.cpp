#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break; // optimization: stop if already sorted
    }
}

int main() {
    int arr[5] = {5, 1, 4, 2, 8};
    bubbleSort(arr, 5);

    cout << "Sorted Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
