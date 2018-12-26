#include <iostream>

using namespace std;

void f(int* x) {
    *x = 20;
}

int main() {
    int x = 10;
    cout << x << endl;
    f(&x);
    cout << x << endl;
}
