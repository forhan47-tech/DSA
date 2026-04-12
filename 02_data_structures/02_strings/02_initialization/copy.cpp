#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1("World");  
    string s2(s1);        // Copy constructor
    cout << s1 << " " << s2 << endl;
    return 0;
}
