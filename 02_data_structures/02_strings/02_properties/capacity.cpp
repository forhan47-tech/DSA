#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";
    cout << "Before: " << s.capacity() << endl;
    s += "GalaxyWorld";
    cout << "After: " << s.capacity() << endl;
}
