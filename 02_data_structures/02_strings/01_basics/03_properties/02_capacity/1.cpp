#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << endl;

    s.reserve(100); // Pre-allocate space
    cout << "Reserved capacity: " << s.capacity() << endl;

    s = "Hello World";
    s.shrink_to_fit();
    cout << "Capacity after reserve: " << s.capacity() << endl;
    return 0;
}
