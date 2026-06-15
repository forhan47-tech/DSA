#include <iostream>
using namespace std;

bool linearSearch(int mat[][3], int r, int c, int key) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(mat[i][j] == key) {
                cout << "Found at (" << i << "," << j << ")\n";
                return true; // stop once found
            }
        }
    }
    return false; // not found
}

int main() {
    int mat[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    int key = 50;

    if(!linearSearch(mat, 2, 3, key)) {
        cout << "Not found\n";
    }
}
