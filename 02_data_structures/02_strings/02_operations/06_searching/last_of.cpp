#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorldHello";

    // Find last of any characters
    size_t lastOf = s.find_last_of("aeiou");
    if (lastOf != string::npos)
        cout << "Last vowel at index: " << lastOf << endl;

    return 0;
}
