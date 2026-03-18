#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorldHello";

    // Find first occurrence
    size_t pos = s.find("World");
    if (pos != string::npos)
        cout << "Found 'World' at index: " << pos << endl;

    return 0;
}
