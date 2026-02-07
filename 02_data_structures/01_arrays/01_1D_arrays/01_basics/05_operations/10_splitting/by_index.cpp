#include <iostream>
using namespace std;

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int mid = n/2;

    cout << "First half: ";
    for(int i = 0; i < mid; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nSecond half: ";
    for(int i = mid; i < n; i++) {
        cout << arr[i] << " ";
    }
}
