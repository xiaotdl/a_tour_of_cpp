#include <iostream>

using namespace std;

class Dog {
public:
    Dog(string name) : name_{name} { cout << "Dog " << name_ << " is born." << endl; };
    ~Dog() { cout << "Dog " << name_ << " is destroyed." << endl; }
private:
    string name_;
};

int main() {
    // abort();
    try {
        Dog dog1("A");
        Dog dog2("B");
        throw 20;
    } catch (int e) {
        cout << e << " is caught" << endl;
    }

}
