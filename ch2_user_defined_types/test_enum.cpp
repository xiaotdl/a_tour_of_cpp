#include <iostream>

using namespace std;

// enum class Color { red, blue, green };
// enum class Traffic_light { green, yellow, red };
//
// Traffic_light& operator++(Traffic_light& t) // prefix increment: ++
// {
//   switch (t) {
//     case Traffic_light::green: return t=Traffic_light::yellow;
//     case Traffic_light::yellow: return t=Traffic_light::red;
//     case Traffic_light::red: return t=Traffic_light::green;
//   }
// }

 // If you don’t want to explicitly qualify enumerator names and want enumerator
 // values to be ints (without the need for an explicit conversion), you can remove
 // the class from enum class to get a ‘‘plain’’ enum. The enumerators from a
 // ‘‘plain’’ enum are entered into the same scope as the name of their enum and
 // implicitly converts to their integer value.

enum IntColor {red, green, blue};

int main() {
  cout << "Hello World!\n";

  // Color col = Color::red;
  // Traffic_light light = Traffic_light::red;
  // Traffic_light next = ++light; // next becomes Traffic_light::green

  cout << IntColor::red << "\n";
  cout << IntColor::green << "\n";
  cout << IntColor::blue << "\n";

  return 0;
}
