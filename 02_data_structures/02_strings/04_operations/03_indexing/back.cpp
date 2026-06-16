#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    cout << s.back() << endl;  // Access last character

    s.back() = '!';   // modify last character
    cout << s << endl;       
}
