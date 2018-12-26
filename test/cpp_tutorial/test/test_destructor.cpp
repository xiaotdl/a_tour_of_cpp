#include <iostream>

using namespace std;

class Dog {
public:
    virtual ~Dog() {cout << "Dog destroyed" << endl;}
    virtual void bark() {};
};

class YellowDog : public Dog {
public:
    ~YellowDog() {cout << "Yellow dog destoryed." << endl;}
};

class DogFactory {
public:
    static Dog* createYellowDog() {
        return new YellowDog();
    }
};

int main() {
    Dog* p = DogFactory::createYellowDog();
    delete p;
}
