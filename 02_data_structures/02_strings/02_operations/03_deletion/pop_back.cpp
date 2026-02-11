#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    // Remove last character
    s.pop_back();
    cout << "After pop_back: " << s << endl;  
    return 0;
}
