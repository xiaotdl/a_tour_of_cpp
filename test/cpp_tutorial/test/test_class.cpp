#include <iostream>

class Rectangle {
    int width, height;
public:
    Rectangle();
    Rectangle(int, int);
    void set_values(int, int);
    int area(void);
};

Rectangle::Rectangle() {};

Rectangle::Rectangle(int width, int height)  
    :width(width), height(height) {}

void
Rectangle::set_values(int width, int height) {
    this->width = width;
    this->height = height;
}

int
Rectangle::area() {
    return width * height;
}

/*
- Pointers (A * a = new A;): N bits on the stack (address) + S bits on the heap (object)

- References (A a; A &ref = a;): N bits on the stack (address) + S bits on the stack (object)

- Direct values (A a;): S bits on the stack (object)
*/

/*
// automatic storage duration - cheap!
ClassName obj;

// dynamic storage duration - marginally more expensive,
// and now you have to `delete` it, too
ClassName* ptr = new ClassName;
*/



int main() {
    Rectangle rect_a, rect_b; // returns ref-like direct value
    Rectangle& ref_a = rect_a;
    Rectangle rect_c{7,8};
    ref_a.set_values(3, 4);
    rect_b.set_values(5, 6);
    std::cout << ref_a.area() << std::endl;
    std::cout << rect_b.area() << std::endl;
    std::cout << rect_c.area() << std::endl;

    Rectangle* p = new Rectangle(); // returns ptr
    Rectangle& ref = *p;
    p->set_values(4, 5);
    std::cout << p->area() << std::endl;
    std::cout << ref.area() << std::endl;
    delete p;

    return 0;
}
