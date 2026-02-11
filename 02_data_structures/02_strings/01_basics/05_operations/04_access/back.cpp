#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    // Access last character
    cout << "Last char using back(): " << s.back() << endl;

    // Modify last character
    s.back() = '!';
    cout << "After modification: " << s << endl;

    return 0;
}
