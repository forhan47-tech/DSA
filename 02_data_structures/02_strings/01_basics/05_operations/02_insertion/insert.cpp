#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    // Insert substring at position 5
    s.insert(5, " Beautiful");
    cout << "After insertion: " << s << endl;

    // Insert single character
    s.insert(0, 1, '*');
    cout << "After inserting char: " << s << endl;

    // Insert using iterators
    s.insert(s.begin() + 6, '-');
    cout << "After inserting with iterator: " << s << endl;

    return 0;
}
