#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    s.insert(5, " Beautiful"); // insert " Beautiful" at index 5
    cout << s << endl; 

    s.insert(s.begin() + 3, 'X');   // Insert 'X' at 4th position
    cout << s << endl;
}
