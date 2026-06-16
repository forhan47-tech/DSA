#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    cout << "Reverse traversal: ";
    for(auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it << " "; 
    }
    cout << endl;
}
