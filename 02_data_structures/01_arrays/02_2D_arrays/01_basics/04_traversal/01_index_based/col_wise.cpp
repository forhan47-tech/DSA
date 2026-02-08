#include <iostream>
using namespace std;

int main() {
    int mat[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int r = 3, c = 4;

    cout << "Column-major traversal:" << endl;
    for(int j = 0; j < c; j++) {
        for(int i = 0; i < r; i++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
