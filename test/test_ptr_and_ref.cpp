#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// const&
// prefer const&: principle of least privilege
void foo(vector<int> v); // pass by value (copy)
void foo(vector<int>& v); // pass by ref, can mutate v
void foo(const vector<int>& v); // pass by ref, can not mutate v

int main() {
  cout << "Hello World!\n";

  // ptr vs. ref
  // ref is an alias to a variable
  // ref is like a symlink
  // ref is implemented through ptr
  // ref is 1) safer, but less powerful
  //        2) cannot be reseated
  //        3) cannot be nulled

  int x = 10;
  // setup
  int* ptr = &x;
  int& ref = x;


  // using the value
  int y;
  y = *ptr;
  y = ref;


  // reseating
  // a ptr can point to anything else
  // a ref cannot
  ptr = &y;
  ref = y; // NOPE, will transfer value, the compiler will bark


  // int* ptr1, ptr2;
  // int *ptr1, *ptr2;
  // int *ptr3;
  // int* ptr4;


  // exceptions
  try {
      //...
  }
  catch (const exception& e) { // almost catch by reference
    cerr << "Error: " << e.what() << endl;
    throw; // rethrow
  }
  catch (...) {
    cerr << "Something bad is happening." << endl;
    throw runtime_error("bad_person_exception");
  }

  // headers
  // used via #include => textual insertion
  // system: #include <iostream>
  // local: #include "folly/Conv.h"
  // @fb
  // system comes from platform and 3rd party
  // local comes from fbcode root
}
