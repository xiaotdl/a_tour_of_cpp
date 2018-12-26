#include <iostream>

using namespace std;

 // A union is a struct in which all members are allocated at the same address
 // so that the union occupies only as much space as its largest member.
 // Naturally, a union can hold a value for only one member at a time.
 // For example, consider a symbol table entry that holds a name and a value:

// enum Type { str, num };
//
// struct Entry {
//   char∗ name;
//   Type t;
//   char∗ s; // use s if t==str
//   int i; // use i if t==num
// };
//
// void f(Entry∗ p) {
//   if (p−>t == str) cout << p−>s;
//   // ...
// }

// The members s and i can never be used at the same time, so space is wasted.
// It can be easily recovered by specifying that both should be members of a union, like this:

// union Value {
//   char∗ s;
//   int i;
// };
//

// struct Entry {
//   char∗ name;
//   Type t;
//   Value v; // use v.s if t==str; use v.i if t==num
// };
//
// void f(Entry∗ p) {
//   if (p−>t == str) cout << p−>v.s;
//   // ...
// }

int main() {
  return 0;
}
