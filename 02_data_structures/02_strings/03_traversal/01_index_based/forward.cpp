#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    cout << "Forward traversal: ";
    for(size_t i = 0; i < s.size(); ++i) {
        cout << s[i] << " ";  
    }
    cout << endl;
}
