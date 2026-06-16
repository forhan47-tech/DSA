#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";

    s += "!!!";             // using operator+=
    cout << s << endl; 

    s = s + " GalaxyWorld";    // using operator+
    cout << s << endl;
}
