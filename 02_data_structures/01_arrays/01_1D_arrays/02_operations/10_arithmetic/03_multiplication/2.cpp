#include <iostream>
using namespace std;

int main() {
    int A[5] = {1, 2, 3, 4, 5};
    int B[5] = {10, 20, 30, 40, 50};
    int C[5];

    cout << "Element-wise multiplication: ";
    for(int i = 0; i < 5; i++) {
        C[i] = A[i] * B[i];
        cout << C[i] << " ";
    }
    cout << endl;
    return 0;
}
