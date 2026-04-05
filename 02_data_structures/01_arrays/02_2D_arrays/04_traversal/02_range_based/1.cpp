#include <iostream>
using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Range-based traversal:" << endl;
    for(auto &row : A){          // iterate over each row
        for(auto &el : row){   // iterate over each element in row
            cout << el << " ";
        }
        cout << endl;
    }
}
