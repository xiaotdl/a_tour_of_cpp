#include <iostream>
#include <string>

using namespace std;

// Deduce type that `auto` inferred during compiling time

class Widget {
public:
    Widget(){};
};

template<typename T>
class TD; // Type Display

int main() {
  const int var = 42;
  auto x = var;
  auto y = &var;
  auto ptr = new Widget;
  // auto ptr = new double[5];

  cout << typeid(x).name() << endl; // i: int
  cout << typeid(y).name() << endl; // PKi: pointer to const int

  // TD<decltype(x)> xType;
  // TD<decltype(y)> yType;
  TD<decltype(v)> ptrType;
  // >>>
  // g++ -Wall -std=c++14 -g -c test.cpp
  // test.cpp:19:19: error: implicit instantiation of undefined template 'TD<int>'
  //   TD<decltype(x)> xType;
  //                   ^
  // test.cpp:9:7: note: template is declared here
  // class TD; // Type Display
  //       ^
  // test.cpp:20:19: error: implicit instantiation of undefined template 'TD<const int *>'
  //   TD<decltype(y)> yType;
  //                   ^
  // test.cpp:9:7: note: template is declared here
  // class TD; // Type Display
}
