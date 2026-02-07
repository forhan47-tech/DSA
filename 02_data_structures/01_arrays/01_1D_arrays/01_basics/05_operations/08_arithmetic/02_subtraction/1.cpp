#include <iostream>
using namespace std;

int main() {
    int arr[5] = {20, 30, 40, 50, 60};

    for(int i = 0; i < 5; i++) {
        arr[i] -= 5; // Subtract 5 from each element
    }

    cout << "Array after subtraction: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
