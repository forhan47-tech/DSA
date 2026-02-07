#include <iostream>
using namespace std;

int main() {
    int A[5] = {1, 2, 3, 4, 5};
    int B[5] = {10, 20, 30, 40, 50};
    int C[5];

    cout << "Element-wise division: ";
    for(int i = 0; i < 5; i++) {
        if(B[i] != 0) {
            C[i] = A[i] / B[i];
            cout << C[i] << " ";
        } else {
            cout << "undefined ";
        }
    }
    cout << endl;
    return 0;
}
