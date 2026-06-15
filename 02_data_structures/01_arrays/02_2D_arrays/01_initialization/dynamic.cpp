#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;

    int** mat = new int*[r];
    for (int i = 0; i < r; i++) {
        mat[i] = new int[c];
    }


    // Free memory
    for (int i = 0; i < r; i++) {
        delete[] mat[i];  // free each row
    }
    delete[] mat;         // free row pointers

    return 0;
}
