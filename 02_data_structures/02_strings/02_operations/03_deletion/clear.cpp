#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    // Clear entire string
    s.clear();
    cout << "After clear: " << (s.empty() ? "String is empty" : s) << endl;

    return 0;
}
