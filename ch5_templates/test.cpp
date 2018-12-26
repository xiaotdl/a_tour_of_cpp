#include <iostream>

using namespace std;

// == Parameterized Types ==
// template<typename T>
// class Vector {
// private:
//   T∗ elem; // elem points to an array of sz elements of type T
//   int sz;
// public:
//   explicit Vector(int s); // constructor: establish invariant, acquire resources  ̃Vector() { delete[] elem; } // destructor: release resources
//   // ... copy and move operations ...
//   T& operator[](int i);
//   const T& operator[](int i) const; int size() const { return sz; }
// };

// Templates are a compile-time mechanism, so their use incurs no run-time overhead compared to hand-crafted code.

// In addition to type arguments, a template can take value arguments. For example:
// template<typename T, int N>
// struct Buffer {
//   using value_type = T;
//   constexpr int size() { return N; }
//   T[N];
//   // ...
// };
// The alias (value_type) and the constexpr function are provided to allow users (read-only) access to the template arguments.


// == Function Templates ==
// template<typename Container, typename Value>
// Value sum(const Container& c, Value v)
// {
//   for (auto x : c) v+=x;
//   return v;
// }

// ==
// The template is C++’s main support for generic pro- gramming. Templates provide (compile-time) parametric polymorphism.

// == Function Object ==
template<typename T>
class Less_than {
  const T val; // value to compare against
public:
  Less_than(const T& v) :val(v) { }
  bool operator()(const T& x) const { return x<val; } // call operator
};

// == lambda ==
// The notation [&](int a){ return a<x; } is called a lambda expression.
// It generates a function object exactly like Less_than<int>{x}.
// The [&] is a capture list specifying that local names used (such as x) will be accessed through references.
// Had we wanted to ‘‘capture’’ only x, we could have said so: [&x].
// Had we wanted to give the generated object a copy of x, we could have said so: [=x].
// Capture nothing is [ ],
// capture all local names used by reference is [&],
// and capture all local names used by value is [=].
// Using lambdas can be convenient and terse, but also obscure.

int main() {
  cout << "Hello World!\n";

  Less_than<int> lti (42); // lti(i) will compare i to 42 using < (i<42)
  cout << lti(50) << endl;
  cout << lti(40) << endl;
}
