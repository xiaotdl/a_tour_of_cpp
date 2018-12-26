#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void print_list(vector<int>& l) {
  for (auto x : l)
    cout << x << "\n";
}

ostream_iterator<string> oo {cout}; // write strings to cout

int main() {
  cout << "Hello World!\n";

  vector<int> v = {1, 0, 3, 2, 4};
  print_list(v);

  sort(v.begin(), v.end());
  print_list(v);

  // What is common for all iterators is their semantics and the naming of their operations.
  // For example, applying ++ to any iterator yields an iterator that refers to the next element.
  // Similarly, ∗ yields the element to which the iterator refers.

  *oo = "Hello, "; // meaning cout<<"Hello, "
  ++oo;
  *oo = "world!\n"; // meaning cout<<"world!\n"
}
