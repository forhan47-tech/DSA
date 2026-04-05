#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorldHello";

    // Find first of any characters
    size_t firstOf = s.find_first_of("aeiou");
    if (firstOf != string::npos)
        cout << "First vowel at index: " << firstOf << endl;

    return 0;
}
