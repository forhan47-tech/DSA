#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    // Extract substring from index 5, length 5
    string sub = s.substr(5, 5);
    cout << "Substring: " << sub << endl;

    // Extract substring from index 0 to end
    string substr = s.substr(0);
    cout << "Substring from start: " << substr << endl;

    return 0;
}
