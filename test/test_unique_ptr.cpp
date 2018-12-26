#include <iostream>

using namespace std;

class Person {
public:
    Person(string name, int age)
    : name{name}, age{age} {};
    string name;
    int age;
};

int main() {
  cout << "Hello World!\n";
  Person p{"Xiaotian", 28};
  cout << p.name << " is " << p.age << " yrs old." << endl;

  Person* pPtr = &p;
  cout << pPtr->name << " is " << pPtr->age << " yrs old." << endl;

  auto wendi = std::make_unique<Person>("Wendi", 29);
  cout << wendi->name << " is " << wendi->age << " yrs old." << endl;
}
