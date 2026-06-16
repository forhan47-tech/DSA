#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    cout << "Reverse traversal: ";
    for(char c : string(s.rbegin(), s.rend())) {
        cout << c << " ";  
    }
}
