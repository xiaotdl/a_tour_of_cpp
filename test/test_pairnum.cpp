#include <iostream>
#include <string>

using namespace std;

string::size_type pair_num(const string& s) {
  if (s.empty()) return 0;

  string::size_type ret = 0;

  auto prev = s.front();
  for (auto it = begin(s) + 1; it != end(s); ++it) {
    if (*it == prev) ++ret;
    prev = *it;
  }
  return ret;
}

int main() {
  cout << "Hello World!\n";


  // cout << "pair nums: " << pair_num("1122344") << endl;
  //
  // int evens[] = {2,4,6,8,10};
  //
  // for (auto i : evens) {
  //   i = 0;
  // }
  // for (auto i : evens) {
  //   cout << i << endl;
  // }
  //
  // for (auto& i : evens) {
  //   i = 0;
  // }
  // for (auto i : evens) {
  //   cout << i << endl;
  // }
  // for (auto* i : evens) {
  //   *(i) = 0;
  // }
  // for (auto i : evens) {
  //   cout << i << endl;
  // }
}
