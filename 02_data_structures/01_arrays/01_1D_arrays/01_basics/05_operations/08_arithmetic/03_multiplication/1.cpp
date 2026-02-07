#include <iostream>
using namespace std;

int main() {
    int arr[5] = {2, 4, 6, 8, 10};

    for(int i = 0; i < 5; i++) {
        arr[i] *= 3;  // Multiply each element by 3
    }

    cout << "Array after multiplication: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
