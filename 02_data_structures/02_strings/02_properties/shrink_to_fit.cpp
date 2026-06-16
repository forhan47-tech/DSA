#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    s.reserve(100); // artificially increase capacity
    cout << "Before: " << s.capacity() << endl;

    s.shrink_to_fit();
    cout << "After: " << s.capacity() << endl;
}
