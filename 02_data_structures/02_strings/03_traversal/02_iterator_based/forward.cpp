#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    cout << "Forward traversal: ";
    for(auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";  
    }
    cout << endl;
}
