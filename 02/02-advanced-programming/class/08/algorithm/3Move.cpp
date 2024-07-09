#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str = "Hello";

    vector<string> strvec;

    strvec.push_back(str);

    cout << "str after copy is: " << str << endl;

    strvec.push_back(std::move(str));

    cout << "str after move is: " << str << endl;
}