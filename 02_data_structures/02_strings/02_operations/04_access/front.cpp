#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    // Access first character
    cout << "First char using front(): " << s.front() << endl;

    // Modify first character
    s.front() = '*';
    cout << "After modification: " << s << endl;

    return 0;
}
