#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    // Replace substring
    s.replace(5, 5, "Universe"); 
    cout << "After replace: " << s << endl;

    return 0;
}
