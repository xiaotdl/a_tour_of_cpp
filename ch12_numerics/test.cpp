#include <iostream>
#include <numeric>
#include <list>

using namespace std;

int main() {
  cout << "Hello World!\n";

  list<double> lst {1, 2, 3, 4, 5, 9999.99999};
  auto s = accumulate(lst.begin(),lst.end(),0.0); // calculate the sum
  cout << s << '\n'; // print 10014.9999
}
