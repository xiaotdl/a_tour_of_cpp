#include <iostream>
#include <string>

using namespace std;

int main() {
    // int a, b;
    // cout << "Please input two values:\n";
    // cin >> a >> b;
    // cout << "The sum of " << a << " and " << b << " is " << a + b << endl;

    string name;
    cout << "what's your name?\n";
    getline(cin, name);
    cout << "Hello " << name << endl;
}
