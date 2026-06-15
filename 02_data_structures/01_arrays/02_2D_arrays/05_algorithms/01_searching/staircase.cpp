#include <iostream>
using namespace std;

bool staircaseSearch(int mat[][4], int r, int c, int key) {
    int i = 0, j = c - 1;    // top-right corner

    while (i < r && j >= 0) {
        if (mat[i][j] == key) return true;
        else if (mat[i][j] > key) j--; // move left
        else i++; // move down
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
    cout << (staircaseSearch(mat, 3, 4, key) ? "Found" : "Not Found");
}
