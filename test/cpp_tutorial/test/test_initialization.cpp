#include <iostream>

using namespace std;

int main() {
    int a=1;               // initial value: 1
    int b(2);              // initial value: 2
    int c{3};              // initial value: 3
    int d{};          // initial value: 0
    int x;                 // initial value undetermined

    auto y = 9;
    decltype(y) z = 10;

    cout << a;
    cout << b;
    cout << c;
    cout << d;

    cout << x;
    cout << y;
    cout << z;

    return 0;
}
