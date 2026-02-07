#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // Divide each element by 2
    for(int i = 0; i < 5; i++) {
        arr[i] /= 2;
    }

    cout << "Array after division: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
