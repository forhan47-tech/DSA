#include <iostream>
using namespace std;

void reflectDiagonal(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    reflectDiagonal(mat);

    cout << "Reflected (Main Diagonal):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}
