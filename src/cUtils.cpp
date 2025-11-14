#include <iostream>
#include <string>

using namespace std;

string readLine(string input) {
    string uInput;
    cout << input;
    getline(cin, uInput);
    while (uInput.empty()) {
        getline(cin, uInput);
    }

    return uInput;
}
