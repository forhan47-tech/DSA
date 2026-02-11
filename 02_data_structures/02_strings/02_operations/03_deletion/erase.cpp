#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    // Erase substring (from position 5, length 5)
    s.erase(5, 5);
    cout << "After erase: " << s << endl;

    // Erase single character
    s = "HelloWorld";
    s.erase(s.begin() + 0); // remove 'H'
    cout << "After erasing first char: " << s << endl;

    return 0;
}
