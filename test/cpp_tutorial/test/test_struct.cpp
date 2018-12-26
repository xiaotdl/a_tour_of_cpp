#include <iostream>

using namespace std;

template<typename T>
class TD; // Type Display

struct B {
    int id;
    string type;
};

struct A {
    int id;
    string type;
    B b;
};

int main() {
    A a{1, "a-type", {3, "b-type"}};
    B b{2, "b-type"};
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << a.b.id << endl;

    auto ptr = &a;
    cout << ptr->b.id << endl;

    const int ci = 0;
    std::cout << type_name<decltype(ci)>() << '\n';

    TD<decltype(&a)> vType;

}
