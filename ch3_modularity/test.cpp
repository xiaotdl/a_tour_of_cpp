#include <iostream>
#include <cmath>
#include "Vector.h"

using namespace std;

// double sqrt_sum(Vector& v) {
//   double sum = 0;
//   for (int i = 0; i != v.size(); ++i) {
//     sum += sqrt(v[i]);
//     cout << sqrt(v[i]) << endl;
//   }
//   return sum;
// }

int main() {
  // cout << "Hello World!\n";
  // static_assert(sizeof(int) >= 4, "integers are too small!"); // check integer size
  Vector v(3);
  cout << v.size() << endl;

  // for (int i = 0; i != v.size(); ++i) {
  //   v[i] = i;
  // }
  // cout << sqrt_sum(v) << endl;
  return 0;
}
