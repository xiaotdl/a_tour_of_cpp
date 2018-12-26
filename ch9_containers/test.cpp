#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <initializer_list>

using namespace std;

// == vector ==
// The most useful standard-library container is vector.
// A vector is a sequence of elements of a given type.
// The elements are stored contiguously in memory.
// A typical implementation of vector (§4.2.2, §4.6) will consist of a handle
// holding pointers to the first element, one-past-the-last element, and one-past-the-last allocated space

// struct Entry {
//   string name;
//   int num;
// };

// vector<Entry> phone_book = {
//   {"David Hume",123456},
//   {"Karl Popper",234567},
//   {"Bertrand Arthur William Russell",345678}
// };

// void print_book(const vector<Entry>& book) {
//   for (int i = 0; i!=book.size(); ++i)
//     cout << book[i] << endl;
// }

// // == list ==
// // iterate through
// int get_number(const string& s) {
//   for (const auto& x : phone_book)
//     if (x.name==s)
//       return x.number;
//   return 0; // use 0 to represent "number not found"
// }
//
// // Using iterators explicitly, we can – less elegantly – write the get_number() function like this:
// // Given an iterator p, ∗p is the element to which it refers, ++p advances p to refer to the next element
// // p->attr is syntactic sugar for (*p).attr
// int get_number(const string& s) {
//   for (auto p = phone_book.begin(); p!=phone_book.end(); ++p)
//     if (p−>name==s)
//       // same as (*p).name
//       return p−>number;
//   return 0; // use 0 to represent "number nkkot found"
// }
//
// void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q) {
//   phone_book.insert(p,ee); // add ee before the element referred to by p
//   phone_book.erase(q); // remove the element referred to by q
// }

// == map ==
// The standard library offers a search tree (a red- black tree) called map.
// In other contexts, a map is known as an associative array or a dictionary. It is implemented as a bal- anced binary tree.

// == unordered_map ==
// The cost of a map lookup is O(log(n)) where n is the number of elements in the map. That’s pretty good.

map<string,int> phone_book = {
  {"David Hume",123456},
  {"Karl Popper",234567},
  {"Bertrand Arthur William Russell",345678}
};


// unordered_map<string,int> phone_book {
//   {"David Hume",123456},
//   {"Karl Popper",234567},
//   {"Bertrand Arthur William Russell",345678}
// };

int get_number(const string& s) {
  return phone_book[s];
}

int main() {
  cout << "Hello World!\n";
  cout << get_number("David Hume") << endl;
  cout << get_number("Xiaotian Li") << endl;
}
