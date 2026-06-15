#include <iostream>
using namespace std;

int main() {
    int mat[][2] = { {10, 20}, {30, 40} };

    int r = sizeof(mat) / sizeof(mat[0]);
    int c = sizeof(mat[0]) / sizeof(mat[0][0]);

    cout << "Matrix Rows: " << r << endl;
    cout << "Matrix Cols: " << c << endl;
}
