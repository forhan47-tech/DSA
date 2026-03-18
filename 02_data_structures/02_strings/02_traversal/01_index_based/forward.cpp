#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Traversal";

    for (size_t i = 0; i < s.length(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    
    return 0;
}
