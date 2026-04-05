#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";
    
    cout << "Forward traversal: ";
    for(auto it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
}
