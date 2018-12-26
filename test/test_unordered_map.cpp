#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> m;
  m["one"] = 1;
  m["two"] = 2;

  for (const auto& p : m) {
    cout << p.first << " => " << p.second << endl;
  }
}
