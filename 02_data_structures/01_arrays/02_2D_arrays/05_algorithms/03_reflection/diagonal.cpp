#include <iostream>
using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = 3;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            swap(A[i][j], A[j][i]);
        }
    }

    cout << "Reflection:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cout << A[i][j] << " ";
        cout << endl;
    }
}
