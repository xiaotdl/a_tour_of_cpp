#include <iostream>

using namespace std;

// class Vector {
//   public:
//     // Vector(int s) :elem{new double[s]}, sz{s} { } // construct a Vector
//     Vector(int s) :elem{new double[s]}, sz{s} { }
//     double& operator[](int i) { return elem[i]; } // element access: subscripting
//     int size() { return sz; }
//   private:
//     double* elem; // pointer to the elements
//     int sz; // the number of elements
// };

// There is no fundamental difference between a struct and a class;
// a struct is simply a class with members public by default.

class Rectangle {
    int width, height;
  public:
    void set_values(int,int);
    int area() {return width*height;}
};

void Rectangle::set_values(int x, int y) {
  width = x;
  height = y;
}

int main() {
  Rectangle rect;
  rect.set_values(3,4);
  cout << "area: " << rect.area() << "\n";
  return 0;
}
