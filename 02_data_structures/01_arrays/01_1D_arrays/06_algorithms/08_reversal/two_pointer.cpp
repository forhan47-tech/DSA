#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    int l = 0, r = n-1;

    while(l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = size(arr);

    reverseArray(arr, n);

    cout << "Reversed array: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
