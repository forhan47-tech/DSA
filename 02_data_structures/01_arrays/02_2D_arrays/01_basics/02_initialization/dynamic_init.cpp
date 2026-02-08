#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    // dynamic allocation
    int** mat = new int*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new int[cols];
    }

    mat[0][0] = 10; // initialization
    mat[0][1] = 20;
    mat[1][0] = 30;
    mat[1][1] = 40;

    // Access
    cout << "mat[0][0]: " << mat[0][0] << endl;
    cout << "mat[0][1]: " << mat[0][1] << endl;
    cout << "mat[1][0]: " << mat[1][0] << endl;
    cout << "mat[1][1]: " << mat[1][1] << endl;

    // Free memory
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];  // free each row
    }
    delete[] mat;         // free row pointers

    return 0;
}
