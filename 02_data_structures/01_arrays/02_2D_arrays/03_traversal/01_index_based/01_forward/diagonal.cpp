#include <iostream>
using namespace std;

int main() {
    int r = 3, c = 3;  // properly declared

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Main diagonal: ";
    for(int i = 0; i < r; i++) cout << mat[i][i] << " "; // row == column

    cout << "Anti diagonal: ";
    for(int i = 0; i < r; i++) cout << mat[i][c - i - 1] << " "; // row+col = n-1
}
