#include <iostream>
using namespace std;

int main() {
    int mat[][2] = { {10, 20}, {30, 40} };

    int rows = sizeof(mat) / sizeof(mat[0]);
    int cols = sizeof(mat[0]) / sizeof(mat[0][0]);

    cout << "Rows: " << rows << endl;
    cout << "Cols: " << cols << endl;
    return 0;
}
