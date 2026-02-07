#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int pos = 2, val = 45;

    arr[pos] = val; // update at given position

    cout << "Array after update: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
