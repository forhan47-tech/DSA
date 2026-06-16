#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    cout << s.front() << endl; // Access first character

    s.front() = 'X';   // Modify first character
    cout << s << endl;         
}
