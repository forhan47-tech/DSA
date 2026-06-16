#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";

    // Add a single character at the end
    s.push_back('!');
    cout << "After push_back: " << s << endl;
    return 0;
}
