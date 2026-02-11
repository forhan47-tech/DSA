#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = size(arr);
    int rev[n];

    for(int i = 0; i < 5; i++) {
        rev[i] = arr[n-i-1];
    }

    cout << "Reversed array: ";
    for(int i = 0; i < 5; i++) {
        cout << rev[i] << " ";
    }
}
