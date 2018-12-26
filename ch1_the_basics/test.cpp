#include <iostream>

using namespace std;

// $ g++ -Wall test.cpp -o test && ./test

double square (double x) {
  return x * x;
}

int count_x (char* p, char x) {
  // count the number of occurrences of x in p[]
  // p is assumed to point to a zero-terminated array of char (or to nothing)
  if (p == nullptr) return 0;

  int cnt = 0;
  for (;p != nullptr; ++p) {
    if (*p == x) ++cnt;
  }
  return cnt;
}

int main() {
  // cout << "Hello World!\n";
  // double x = 2.0;
  // cout << "The square of " << x << " is: " << square(x) << "\n";
  cout << sizeof(char) << "\n";
  cout << sizeof(int32_t) << "\n";
  cout << sizeof(int64_t) << "\n";

  // char chars[6]; // [] array of 6 chars
  // char* p; // * pointer to char
  //
  // char* p = &chars[3]; // p points to v’s fourth element
  // char c = *p; // *p is the object that p points to

  // In a declaration, suffix * means: pointer to
  // In an expression, prefix ∗ means: contents of

  // In a declaration, suffix & means: reference to
  // In an expression, prefix & means: address of

  // A reference is similar to a pointer, except that you don’t need to use a
  // prefix ∗ to access the value referred to by the reference.
  // Also, a reference cannot be made to refer to a different object after its initialization.

  int v[] = {0,1,2};
  for (auto& x : v) {
    x++;
  }
  for (auto x : v) {
    cout << x << "\n";
  }

  char v[] = {'a', 'b', 'b', 'b', '\0'};
  cout << count_x(&v, 'b');

  // When used in declarations, operators (such as &, ∗, and [ ]) are called *declarator operators*:
  // T a[n]; // T[n]: array of n Ts
  // T∗ p; // T*: pointer to T
  // T& r; // T&: reference to T
  // T f(A); // T(A): function taking an argument of type A returning a result of type T

  // << output operator (‘‘put to’’)
  // >> input operator (‘‘get from’’)
}
