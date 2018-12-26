#include <iostream>

using namespace std;

using namespace std::chrono; // see §3.3


int main() {
  cout << "Hello World!\n";
  auto t0 = high_resolution_clock::now();
  // do_work();
  int x = 0;
  for (int i = 0; i < 1000000; i++)
    x++;
  auto t1 = high_resolution_clock::now();
  cout << duration_cast<milliseconds>(t1-t0).count() << "msec\n";
}
