#include <iostream>
using namespace std;

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int r = 3, c = 3;  // properly declared

    cout << "Main diagonal: ";
    for(int i = 0; i < r; i++) {
        cout << mat[i][i] << " ";
    }

    cout << "\nSecondary diagonal: ";
    for(int i = 0; i < r; i++) {
        cout << mat[i][c - i - 1] << " ";
    }
    return 0;
}
