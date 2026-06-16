#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";

    cout << "Capacity: " << s.capacity() << endl;

    s += "WorldUniverse";
    cout << "New Capacity: " << s.capacity() << endl;
}
