#include <iostream>
#include <string>
using namespace std;

int main() {
    string floatStr = "45.67";

    // Convert string to double
    double val = stod(floatStr);
    cout << "Double: " << val << endl;

    return 0;
}
