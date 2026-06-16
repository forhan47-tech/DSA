#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "World";
    cout << "Before: " << s.capacity() << endl;   
    s.reserve(50); // request capacity for 50 chars
    cout << "After: " << s.capacity() << endl;
}
