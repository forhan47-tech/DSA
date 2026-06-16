#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
    string text = "apple, banana|orange; grape";
    regex re("[,|; ]+");   // delimiters

    sregex_token_iterator it(text.begin(), text.end(), re, -1);
    sregex_token_iterator end;

    for (const auto& tok : vector<string>(it, end)) {
        cout << tok << endl;
    }
}
