#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorldHello";

    // Find last occurrence
    size_t lastPos = s.rfind("Hello");
    if (lastPos != string::npos)
        cout << "Last 'Hello' at index: " << lastPos << endl;

    return 0;
}
