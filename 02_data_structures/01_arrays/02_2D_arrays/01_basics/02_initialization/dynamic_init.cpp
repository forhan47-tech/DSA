#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    // dynamic allocation
    int** mtx = new int*[rows];
    for (int i = 0; i < rows; i++) {
        mtx[i] = new int[cols];
    }

    mtx[0][0] = 10; // initialization
    mtx[0][1] = 20;
    mtx[1][0] = 30;
    mtx[1][1] = 40;

    // Access
    cout << "mtx[0][0]: " << mtx[0][0] << endl;
    cout << "mtx[0][1]: " << mtx[0][1] << endl;
    cout << "mtx[1][0]: " << mtx[1][0] << endl;
    cout << "mtx[1][1]: " << mtx[1][1] << endl;

    // Free memory
    for (int i = 0; i < rows; i++) {
        delete[] mtx[i];  // free each row
    }
    delete[] mtx;         // free row pointers

    return 0;
}
