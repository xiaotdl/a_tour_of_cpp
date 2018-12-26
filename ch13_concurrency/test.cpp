#include <iostream>
#include <thread>
// #include <initializer_list>

using namespace std;

void f1() {
  for (int i = 0; i < 100; i++) {
    cout << "running XX...\n";
  }
}

void f2() {
  for (int i = 0; i < 100; i++) {
    cout << "running OO...\n";
  }
}

int main() {
  cout << "Hello World!\n";
  thread t1 {f1};
  thread t2 {f2};

  t1.join();
  t2.join();
}
