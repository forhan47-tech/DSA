#include <iostream>
using namespace std;

bool staircaseSearch(int mat[][4], int r, int c, int key) {
    int i = 0;        // start at first row
    int j = c - 1;    // start at last column (top-right corner)

    while (i < r && j >= 0) {
        if (mat[i][j] == key) {
            cout << "Element found at row " << i << ", column " << j << endl;
            return true;
        }
        else if (mat[i][j] > key) {
            j--; // move left
        }
        else {
            i++; // move down
        }
    }
    return false;
}

int main() {
    int mat[3][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48}
    };

    int key = 29;

    if (staircaseSearch(mat, 3, 4, key)) {
        cout << "Search successful!" << endl;
    } else {
        cout << "Element not found" << endl;
    }
}
