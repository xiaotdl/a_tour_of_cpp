#include <iostream>
#include <array>

using namespace std;

// # funcitons
bool isEven(int num) {
    return (num % 2) == 0;
}

// // # basic types
// void basic_types() {
//     int id = 123;
//     string name = "xiaotian"; // prefer string over char[]
//     bool isViewer = true;
//     char midInitial = 'x';
//     short editCnt = 9;
//     double createdTime = 234.23;
//     long double deleteTime = 9;
//     unsigned flags = 0x0;
//     const unsigned maxFriends = 20; // compile time constant, prefer const over macros for const val
//     array<string, maxFriends> friends; // prefer array<T, S> over classic T[S] for fixed size array
// }

// // # std constants
// void standard_constants() {
//     auto saved = true; // type infered to be bool by compiler, true/false preferred over 1/0
//     auto dirty = false; // cout will show 1 for true, 0 for false
//     shared_ptr<char> buffer = nullptr; // null pointer value, preferred over NULL or 0
// }

// # arithmetic: +, -, *, /, %, ++, --
// # comparison: ==, !=, !, <, <=, >, >=
// # logical: &&, ||
// # bitwise: &, |, ^, ~

// # variables and scope
void var_and_scope() {
    int readCnt = 0; // explicit type declaration
    // int likeCnt = 0; // declared but uninitialized
    {
        auto readCnt = 9; // block variable shadows local readCnt
        cout << readCnt << endl; // >>> 9
    }
    cout << readCnt << endl; // >>> 0
}

// # references
// Warning - avoid raw pointer use. See later
// Warning - only use references for:
//      1) passing data to functions (either to modify or as an efficient way to avoid passing value), 
//      2) As return types of operator overload functions. Never keep or hold a reference or return them from functions
void referenceGood(int& r) { // ref to an int
    r = 40; // modify the referenced obj
}

// void referenceBad(const int& r) { // const ref to msg
//     r = 20; // !!!compile error!!!
// }

void references() {
    int x = 10;
    referenceGood(x);
    cout << x << endl; // >>> 0
}

// # conditions and control flow: if/else if/else, switch/case/default
// Warning - never use un-braced single block statements: if(condition) statement;

// # loops
void loops() {
    array<string, 4> msgs = {{"a", "b", "c", "d"}};

    for (int i = 0; i < msgs.size(); ++i) {
        string& m = msgs[i];

        if (m == "c") {
            cout << "found c will break" << endl;
            break;
        }

        if (m == "a") {
            cout << "found a will continue" << endl;
            continue;
        }

        cout << "msg: " << m << endl;
    }
}

// # structures and classes
// Note - struct is a class with all members being public by default
// Note - Always use uniform initialization (see later) for initializing values. It provides stronger compiler support for type checking. It handles parameters and collections uniformly. And, it allows return of constructed values without using the type name.
struct Person {
    string name;
    int age;
};

// ## construct
void structConstruct() {
    Person jon{"jon snow", 30};
    cout << jon.name << " is " << jon.age << " old" << endl;
}

// ## pass by reference
void makeOlder(Person& p) {
    p.age += 1;
}

void cpp_StructByRef() {
  Person jon{"jon snow", 30};
  makeOlder(jon);
  cout << jon.name << " is " << jon.age << " old" << endl;
}

// ## return as value
Person makePerson(string first, string last, int age) {
    string name = first + " " + last;
    // In the expression Person{name,age} this is called **uniform initialization**. It is an effective replacement for legacy() based initialization
    return Person{name, age};
}

void cpp_StructRetAsValue() {
  Person jon = makePerson("jon", "snow", 30);
  cout << jon.name << " is " << jon.age << " old" << endl;
}

void _struct() {
    structConstruct();
    cpp_StructByRef();
    cpp_StructRetAsValue();
}

// # class
//
// ## class declaration
// Typically, you would separate the declaration of a class in a header (.h) file and the implementation in a (.cpp) file.
// Future work on C++ 17 introduces modules which will allow the declaration and implementation of a class to be united into a single file with the compiler being able to produce importable declarations into other modules.

class Message {
public:                                          // public members
  Message(string from, string to, string subj);  // constructor method
private:                                         // private members
  string from_;                                  // field member
  string to_;                                    // field member
  string subj_;                                  // field member
};
// Using trailing underscores for fields separates them visually from function arguments, locals,
// and makes it easier to use auto completion editor tools to enter them (than leading underscore field names).
//
// ## class implementation
Message::Message(string f, string t, string s)  // Method impl
: from_{f}, to_{t}, subj_{s} {                  // Member initializer
  cout << "Message created" << endl;            // Method body
}
// The : after the method implementation is a **base member initializer**.
// In the example above, it would have been ok to initialize all members inside the function body
// But some members such as const must be initialized using member initializer
// And member initializer allows calling base class constructors.
// Note - Always use member initializers to call base class constructors and to initialize const members

// # enumerations
void cpp_EnumClass() {
    enum class ValType { Number, Bool, String };
    auto t = ValType::String;

    switch(t) {
        case ValType::Number:
            cout << "number" << endl;
            break;
        case ValType::Bool:
            cout << "boolean" << endl;
            break;
        case ValType::String:
            cout << "string" << endl;
            break;
    }
}

// # namespaces
// Warning - Implicit namespaces should only be used for std library modules or inside your own implementation files of your own classes
// People/Friend.h
namespace People {
  class Friend {
  public:
    Friend(string name) : name_(name) { }
  private:
    string name_;
  };
}

void cpp_NamespaceExplict() {
    People::Friend bw{"bruce wayne"};
    cout << typeid(bw).name() << endl;
    cout << &bw << endl;
}

void cpp_NamespaceImplict() {
    using namespace People;
    Friend ww{"wonder woman"};
    cout << typeid(ww).name() << endl;
    cout << &ww << endl;
}

// # exceptions
// Common exceptions: std::out_of_range, std::length_error, std::bad_alloc

#include <stdexcept>

// ## exception throwing
void cpp_ExceptionsThrow() {
    auto x = 200;
    if (x > 20) {
        throw out_of_range("too large!!!");
    }
}

// ## exception catching
void cpp_ExceptionsTryCatch() {
  try {
    cpp_ExceptionsThrow();
  } catch(out_of_range) {
    cout << "exception: out of range" << endl;
  }
}

// ## exception re-throwing
void cpp_ExceptionsRethrow() {
  try {
    cpp_ExceptionsThrow();
  } catch(out_of_range) {
    cout << "exception out of range" << endl;
    throw;
  }
}

// # methods
// Methods are functions which operate on instance of the class
// const after the method arguments indicates method does not modify data
// It is possible to define methods inside of class declaration (header .h file) or in the associated implementation .cpp file.
// Note - Always suffix methods which do not modify state as const
// Warning - You cannot name methods the same as fields

class Animal {
public:
    Animal(string name, float weight)
    : name_{name}, weight_{weight} { }
    string getName() const { return name_; }
    string getWeight() const { return to_string(weight_) + "lbs"; }
private:
    string name_;
    float weight_;
};

void cpp_Methods() {
    // Animal duck("donald", 8.6);
    Animal duck{"donald", 8.6};
    cout << duck.getName() << " is " << duck.getWeight() << endl;
}

// # static methods
// Static methods operate at the class level (as global functions) rather than individual object instances

class Entity {
public:
    Entity(string name): name_{name} {}
    static Entity MakeAnEntity(string name);
    string name_;
};

Entity Entity::MakeAnEntity(string name) {
    return Entity{"Static " + name};
}

void cpp_StaticMethods() {
    auto ent = Entity::MakeAnEntity("gizmo");
    cout << ent.name_ << endl;
}

// # class containment
struct Attachment {
  string content;
};

struct ModularMessage {
  string from;
  string to;
  Attachment attachment;
  ModularMessage(string f, string t, string c) : from{f}, to{t}, attachment{c} {}
};

void cpp_ClassContainment() {
  ModularMessage mm{"john", "jane", "hello"};
  cout << mm.from << " send " << mm.attachment.content << " to " << mm.to << endl;
}

// # class destructors
// Sometimes classes contain values that are handles to other types of resources (files, network sockets, operating system bitmaps, locks ...etc).
// These require explicit cleanup and the class author needs to know when the object is being destructed so they can free or close the resources. Destructors are methods used to handle with these situations
//
// - Destructors are called when objects are no longer needed
// - If stack allocated, when the execution leaves the scope block
// - If explicitly allocated, when delete is called
// - When using unique_ptr, when the owning object is destructed (see later)
// - When using shared_ptr, when the last reference is removed (see later)
//
// Warning - Never use explicit new and delete operations to create and delete objects. Read further to learn about resource management
// Warning - Only use destructors when using members which are not C++ classes or primitive types. Otherwise all destructor logic is automatically handled by the compiler

#include <stdio.h>
class File {
public:
  File(string name) {
    file_ = fopen(name.c_str(),"w");
    cout << "opened " << name << endl;
  }
  ~File() {
    fclose(file_);
    cout << "closed file" << endl;
  }
private:
  FILE* file_;
};
  
void cpp_Destructors() {
  { // block scoped but typically function scoped
    File f{"foo"};
  }
  cout << "the file should be closed now" << endl;
}

// # RESOURCE ACQUISITION IS INITIALIZATION (RAII)
// Having class destructors and class containment allows for efficient and reliable mechanisms for resource reclamation in C++. See in the example above how the file was guaranteed to be closed as soon as it went out of scope. Similar mechanisms can be used for locks and other scenarios.
// Note - Always use value classes with constructors and destructors to scope resource usage to method or block invocations
// Note - This is effective for all non-object resources (file handles, bitmaps, network sockets, operating system locks and much more). It is one of C++ main strengths!


// # virtual functions and inheritance
// Inheritance allows classes to share parts of a parent class implementation.
//
// - By default in C++ methods are not virtual and a subclass does not inherit the implementation of a method or be able to override it. Only methods declared as virtual can be overridden by a subclass.
// - virtual bool canBeInGroups() = 0; is a “pure virtual function” and has no implementation
// - As a result class Contact is an abstract class and cannot be instantiated
// - Person's constructor calling: Contact{n} is to ensure the base constructor is run for a Person
// - Page accepts Contact's implementation of canVideoCall which defaults to no.
// - It is also possible for page to explicitly declare canVideoCall and return Contact::canVideoCall()
// - Person explicitly overrides Contact's canVideoCall and canBeInGroups methods
//
// Note - Always use override to be clear on overriding functions. This addresses misspelled child class functions type problems
// Warning - Always make destructors virtual if using inheritance to ensure that the proper subclass destructor is called.
// Warning - While C++ allows it, avoid use of multiple inheritance. Except for inheriting from pure virtual (interface) classes

struct Contact {
  Contact(string n) : name{n} {}
  virtual bool canVideoCall() { return false; };
  virtual bool canBeInGroups() = 0;
  string name;
};
  
struct PersonContact : public Contact {
  PersonContact(string n, string p) : Contact{n}, phone{p} {}
  virtual bool canVideoCall() override { return true; }
  virtual bool canBeInGroups() override { return true; }
  string phone;
};
  
struct PageContact : public Contact {
  PageContact(string n) : Contact(n) {}
  virtual bool canBeInGroups() override { return false; }
};

void cpp_Inheritance() {
  PersonContact sandy{"sandy", "555-1212"};
  PageContact soccer{"soccer"};
  cout << sandy.name << "call:" << sandy.canVideoCall() << " group:" << sandy.canBeInGroups() << endl;
  cout << soccer.name << "call:" << soccer.canVideoCall() << " group:" << soccer.canBeInGroups() << endl;
}

// # strings
// - You can use s.c_str() to obtain a raw character array
// - Short strings use built-in storage and are very efficient when stack allocated or contained in classes
// - Longer strings will use heap allocated character arrays
// - Default string is basic_string<char>, you can use basic_string<OtherCharType> if needed
// - There is no standard for utf8 encoding and decoding. That requires additional libraries
// - Strings support move operations and can be returned by value efficiently (see below)

string to_lower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void cpp_Strings() {
    string s = "Hello";
    s += ", World!";
    cout << s << endl;
    cout << to_lower("ABC") << endl;
}

// # Vectors
// - Sequence of elements of any type
// - Can be pre-allocated with capacity
// - Grows dynamically
// - Efficient index access
// - Efficient iterator access (see later)
// - Expensive element removal
//
#include <vector>

void cpp_Vectors() {
  vector<Person> contacts = {
    { "Sandy", 27 },
    { "Sam", 31 },
    { "Kay", 51 }
  };
  
  cout << contacts.size() << endl;                 // 3
  contacts.reserve(90);                            // capacity 90, size 3
  contacts.push_back({"Jay", 52 });                // size 4
  cout << contacts.size() << endl;                 // 4
  cout << contacts[0].name << endl;                // Sandy
  // cout << contacts[9].name  << endl;            // crash no range check
  try {
    cout << contacts.at(9).name  << endl;          // out_of_range exception
  } catch(exception e) {
    cout << "exception" << endl;
  }
  contacts.erase(contacts.begin()+2);              // remove "Kay" contact
  cout << contacts.size() << endl;                 // 3
  contacts.erase(contacts.begin(),contacts.end()); // contacts is empty
  cout << contacts.size() << endl;                 // 0
}

// # Iterators
//
// - The actual type of c above is vector<Person>::iterator
// - You will need this type if you pass iterators to functions as arguments
//
// Warning - Avoid using[index]operators to index into the vector unless bounds checks have already been performed and you are confident there are no out of bounds conditions. Otherwise, always use .at(index) and handle any resulting out_of_range exceptions
// Note - Always use auto& for getting a reference instead of a pointer of each element
// Note - Always use const auto& for getting a read only reference of each element


void cpp_Iterators() {
  vector<Person> contacts = {
    { "Sandy", 27 },
    { "Sam", 31 },
    { "Kay", 51 }
  };
  for(const auto& c : contacts) {
    cout << c.name << ", " << c.age << endl;   // print contact
  }
}

// # arrays

#include <array>

struct Node {
  array<float,3> translation;
  array<float,3> rotation;
  array<float,3> scaling;

  vector<Node> children;
};

void cpp_Arrays() {
  Node n{ {{ 1,2,3 }}, {{4, 5, 6}}, {{1, 1, 1}}, {} };
  cout << "x0: " << n.translation[0] << ", r1: " << n.rotation[1] << endl;
}

// # lambdas
void cpp_Lambdas() {
  auto d = 90;
  auto c = 100;

  auto no_capture = [](int z) {
      // d = z * 3;      // compile error => can't change d
    return z * 3;
  };

  auto capture_all_by_ref = [&](int z) {
    d = z;
    c = z;
  };

  auto capture_one_by_ref = [&d](int z) {
    d = z * d;
  };

  auto capture_all_by_copy = [=](int z) {
      // d = z * 3;      // compile error => can't change d
  };

  auto capture_d_by_ref_c_by_copy = [&d,c]() {
    d =  c * d;
    // c = d * 3;      // compile error => can't change c
  };

  auto print_copy_captured_values = [=]() {
    // d= 90, c=100 at time of definition
      std::cout << "print_copy_captured_values: d = " << d << ", c = " << c << std::endl;
  };

  auto print_ref_captured_values = [&]() {
    // d= 90, c=100 at time of definition
    std::cout << "print_ref_captured_values: d = " << d << ", c = " << c << std::endl;
  };

  no_capture(10);
  std::cout << "no_capture: d = " << d << ", c = " << c << std::endl; // Prints d=90 c=100

  capture_all_by_ref(20);
  std::cout << "capture_all_by_ref: d = " << d << ", c = " << c << std::endl; // Prints d=20  c=20

  capture_one_by_ref(30);
  std::cout << "capture_one_by_ref: d = " << d << ", c = " << c << std::endl; // Prints d=600 c=20

  capture_all_by_copy(40);
  std::cout << "capture_all_by_copy: d = " << d << ", c = " << c << std::endl; // Prints d=600 c=20

  capture_d_by_ref_c_by_copy();
  std::cout << "capture_d_by_ref_c_by_copy: d = " << d << ", c = " << c << std::endl; // Prints d=60000 c=20

  print_copy_captured_values(); // Prints d=90 c=100

  print_ref_captured_values(); // Prints d=60000 c=20
}


// # Lambdas can have an optional return type -> but compilers can often infer the intended type

// # FIND WITH ITERATORS
// Iterators can be used to modify values in-place and mutate vectors
// Warning - Always consider using non-mutable / reactive approaches for modifying content where possible.
void cpp_FindWithIterators() {
  vector<Person> contacts = {
    { "Sandy", 27 },
    { "Sam", 31 },
    { "Kay", 51 }
  };
  auto start = contacts.begin();
  auto end = contacts.end();
  string lookFor = "Sam";
  auto p = find_if(start, end, [=](const Person& o) -> bool {
    return o.name == lookFor;
  });
  
  if (p == end) {
    cout << "not found" << endl;
  }
  cout << "found " << lookFor << " age " << p->age << endl;
}

// # Initializer Lists
// initializer_list is used to allow literal complex expressions to be used to initialize containers (vectors, lists, ...etc.)
// Note - Always use intializer_list if your constructor or methods accept arbitrary amounts of typed data

class MultiTargetMessage {
public:
  MultiTargetMessage(string f, initializer_list<string> t) : from_{f}, to_{t} {}
  string from_;
  vector<string> to_;
};

void cpp_InitializerLists() {
  MultiTargetMessage m{"admin", {"jack", "jill", "sam"} };
  cout << "second to is " << m.to_[1] << endl;
}

// # Operator Overloading
// Warning - Do not use operator overloading in cases not mentioned in this document (assignment operations, and serialization)


// # Explicit Constructors
// Warning - Avoid implicit conversion of classes where constructors are matched based on RHS type. Always use explicit to avoid these types of problems!

struct AllowsImplicit {
  AllowsImplicit(int x) : data_{x} {}
  vector<int>data_;
};

struct OnlyExplicit {
  explicit OnlyExplicit(int x) : data_{x} {}
  vector<int> data_;
};

void cpp_ExplicitConstructors() {
  AllowsImplicit constructAllowsImplicit(10);
  AllowsImplicit assignAllowsImplicit = 20;
  OnlyExplicit constructAllowsExplicit(30);
  // OnlyExplicit assignOnlyExplicit = 40; <<<< Will not compile
}

// # Type Alias
void cpp_Using() {
  using StringIntVector = vector<pair<string, int>>;
  StringIntVector siv = { { "hi", 1 }, { "world", 2 } };
  cout << siv[0].first << "," << siv[0].second << endl;
}
// - using T = U; used to alias a type
// - Useful for aliasing long type names
// - Such as used with unique_ptr or shared_ptr (see later)
// - Cleaner than legacy typedef
// - Warning - Do not use legacy typedef. Always type alias with using since it is more consistent with template use and has a cleaner more modern syntax.

// # On References and Pointers 
// References are typically used to be able to modify a value passed to a function. They can also be used to pass a reference to an object instead of copying it to functions. But:
// - References can never be null which means they cannot be used for optional values
// - References do not have ownership semantics, so objects cannot be deleted using references
//
// There are 3 kinds of pointers:
// 1) unique_ptr<> allows one object to own another object,
// 2) shared_ptr<> allows an object to be shared amongst other objects, 
// 3) weak_ptr<> is used when no ownership is needed.
//
// Warning -Do not use legacy C-style raw pointers and deletealways use containment, unique_ptr, or shared_ptr
//
// ## unique ptr
// unique_ptr拥有它所指向的对象，在某一时刻，只能有一个unique_ptr指向特定的对象
// 当unique_ptr被销毁时，它所指向的对象也会被销毁。因此不允许多个unique_ptr指向同一个对象，所以不允许拷贝与赋值。

using UniqueAttachment = unique_ptr<Attachment>;

struct MessageWithDynamicAttachment {
  UniqueAttachment attachment;
  void makeAttachment() {
    attachment = UniqueAttachment{new Attachment()};
  }
};

void cpp_UniquePointers() {
  MessageWithDynamicAttachment m;
  cout << "has attachment " << (m.attachment != nullptr) << endl;
  m.makeAttachment();
  cout << "has attachment " << (m.attachment != nullptr) << endl;
}

// # Dynamci Cast 
// dynamic_cast allows checking an object type at runtime. It is equivalent to instanceof in other languages
struct Base {
  virtual void something() { }        // to allow polymorphism
};
struct Derived1 : public Base {
};

struct Derived2 : public Base {
};

void cpp_DynamicCast() {
  using UniqueBase = unique_ptr<Base>;
  
  UniqueBase b1 = UniqueBase{ new Derived1 };
  UniqueBase b2 = UniqueBase{ new Derived2 };
  
  cout << "b1 " << dynamic_cast<Derived1*>(b1.get()) << endl;
  cout << "b1 " << dynamic_cast<Derived2*>(b1.get()) << endl; // Prints b1 0x0
  cout << "b2 " << dynamic_cast<Derived1*>(b2.get()) << endl; // Prints b2 0x0
  cout << "b2 " << dynamic_cast<Derived2*>(b2.get()) << endl;
}

// Note: Most implementations (but not all) represent the null pointer by address 0.

// # Shared Pointers
// The safest and easiest (most recommended) way to compose, use, share, and overall use objects is to simply use shared_ptr. It allows dynamic creation of objects, supports efficient passing by pointer, allows the recipient to hold on to the objects.


using Bytes = vector<char>;
using SharedBytes = shared_ptr<Bytes>;

struct Buffer {
  void takeData(SharedBytes d) { data_ = d; }
  void clearData() { data_ = nullptr; }
  SharedBytes data_;
};

void cpp_SharedPointers() {
  auto d1 = SharedBytes{ new Bytes(2000) };

  cout << "d1 has " << d1.use_count() << " references" << endl;
  Buffer b1;
  b1.takeData(d1);                             // d1 has 2 references
  cout << "d1 has " << d1.use_count() << " references" << endl;
  Buffer b2;
  b2.takeData(d1);                             // d1 has 3 references
  cout << "d1 has " << d1.use_count() << " references" << endl;
  b1.clearData();                              // d1 has 2 references
  cout << "d1 has " << d1.use_count() << " references" << endl;
  b2.clearData();                              // d1 has 1 references
  cout << "d1 has " << d1.use_count() << " references" << endl;
  d1 = nullptr;                                // d1 has 0 refs -> destructed
}

// # Regular Expressions
// Raw string literals R"(...)” does not escape \
// 

#include <regex>

void cpp_Regex() {
  auto matchZipCode = [](string zip) {
      regex pattern{R"((\w{2}\s)*\d{5}(-\d{4})?)"};
      smatch matches ;
      return regex_search(zip, matches, pattern);
  };
  cout << matchZipCode("96816") << endl;                // true
  cout << matchZipCode("H234") << endl;                 // false
  cout << matchZipCode("CA 55434-1234") << endl;        // true
}

// # REGULAR EXPRESSION ITERATORS
void cpp_RegexIterators() {
  string inp = "11 a; a123 999";
  auto end = sregex_iterator{};
  regex pat{R"(\d+[\s|$])"};
  for(sregex_iterator p(inp.begin(),inp.end(),pat); p!=end; p++) {
    cout << (*p)[0] << ' ';                              // 11 123 999
  }
  cout << endl;
}

// # Containers 

// ## list
// Double linked list with efficient erase operations
#include <list>
void cpp_List() {
  auto print = [](list<int> l) {
    for(const auto& i : l) {
      cout << i << " ";                  // 9 3 1
    }
    cout << endl;
  };
  std::list<int> l = { 9, 3, 1 };
  print(l);
  l.insert(l.begin(), 2);                // 2 9 3 1
  print(l);
  auto e = l.end();
  e--;
  l.erase(e);                            // 2 9 3
  print(l);
}

// ## map 
// A tree based implementation of a dictionary (mapping one value to another). Results in ordered traversal of keys
// Note - Always use find and map.end() instead of index access to check if keys are present in a map

#include <map>
void cpp_Map() {
  map<string,int> m = {{"Jane", 9}, {"Joe", 12}, {"Kay", 1}};
  cout << m["Jane"] << endl;                      // 9
  cout << m["Kim"] << endl;                       // Dangerous 0 is default
  m["Kim"] = 17;
  cout << m["Kim"] << endl;                       // 17
}

// ## unordered_map
// Hash table implementation of a dictionary. No order of key traversal but more efficient than map
// - Hash table
// - Possibly faster lookups than O(log(n))
// - For integers and strings uses standard hash functions
// - Will require a custom hash function for non-string / integer keys. Value type must be a class with a custom size_t operator(const T& x) const operator overload to call for hashing
//
// Note - For most dictionary uses, unordered_map<>is superior than map<> for dictionary objects. Always use unordered_map<> unless you have a specific need to traverse keys in order
// Warning - Always use find and unordered_map.end() instead of index access to check if keys are present in a unordered_map

#include <unordered_map>
void cpp_UnorderedMap() {
  unordered_map<string,int> m = {{"Jane", 9}, {"Joe", 12}, {"Kay", 1}};
  cout << m["Jane"] << endl;                      // 9
  cout << m["Kim"] << endl;                       // Dangerous 0 is default
  m["Kim"] = 17;
  auto p = m.find("Kim");
  cout << p->second << endl;                      // 17
}


// ## other
//
// - forward_list<T> - single linked list
// - deque<T> - double ended queue
// - set<T> - map without values (no duplicates)
// - multiset<T> - set which allows duplicates
// - multimap<K,V> - duplicate keys allowed
// - unordered_multimap<K,V> - hash table with duplicate keys allowed
// - unordered_set<T> - set implemented with hash table
// - unordered_multiset<T> - set with duplicates using hash table

// ## COMMON CONTAINER OPERATIONS
// - begin(), end() - iterator markers
// - push_back()- insert at the end
// - size() - get size
// - insert() - insert before iterator
// - erase() - erase from up to iterators


// # algorithms
void cpp_Algorithms() {
  vector<int> v = { 9, 3, 7, 9 };

  sort(v.begin(), v.end());                             // 3 7 9 9
  for(const auto& i : v) {
    cout << to_string(i) << " ";
  }
  cout << endl;

  list<int> l;
  unique_copy(v.begin(), v.end(), back_inserter(l));    // 3 7 9
  for(const auto& i : l) {
    cout << to_string(i) << " ";
  }
  cout << endl;
  
  map<string, int> m = {{"Abc",1}, {"Work",90}};
  auto pred = [](const pair<string,int>& r) {
    return r.second>10;
  };
  auto r = find_if(m.begin(), m.end(), pred);
  cout << r->first << endl;                             // Work
}

// # Streams and Serialization
//
// ostream - output stream: object to byte buffer I/O
// istream - input stream: bytes to object
// cin - console text input istream
// cout - console text output ostream
// cerr - console error output ostream
// Chaining → cin >> i >> d; - read stream into i then d chaining works because stream reading breaks on whitespace and line terminators. This is handy for simple command line processing functions (regular expressions should be used for complex string parsing)
// Chaining → cout << i << "," << d; - print <value of i>,<value of d>
// getline(cin, str); - read string from input terminated by \n
// while(cin >> str) cout << str; → >> will return a reference to istream, istream will evaluate to true if stream has more content
// Alternatively cin.eof(), cin.fail()
// cin.reset() reset to good state
// cin.setstate(ios_base::failbit) - force error state

// # stream iterators

// # time

#include <chrono>
#include <thread>
void cpp_Time() {
  using namespace std::chrono;
  auto t1 = high_resolution_clock::now();
  this_thread::sleep_for(milliseconds{250});
  auto t2 = high_resolution_clock::now();
  cout << duration_cast<milliseconds>(t2 - t1).count() << "ms\n";
}

// # math
#include <cerrno>
#include <cmath>                                // float, double, long double

void cpp_Math() {
  cout << abs(-1)     << ", "     <<  ceil(3.1)   << "\n";
  cout << floor(3.1)  << ", "     <<  sqrt(4)     << "\n";
  cout << cos(3.14)   << ", "     <<  sin(3.14)   << "\n";
  cout << tan(0.1)    << ", "     <<  acos(0)     << "\n";
  cout << asin(1)     << ", "     <<  atan(0)     << "\n";
  cout << sinh(0.1)   << ", "     <<  cosh(0.1)   << "\n";
  cout << tanh(0.1)   << ", "     <<  exp(2)      << "\n";
  cout << log(3)      << ", "     <<  log10(3)    << "\n";
  
  auto i = sqrt(-1);                              // bad real math
  cout  << isnan(i) << endl;               // true
  auto max = numeric_limits<double>::max();
  auto j = pow(max,2);
  cout << isinf(j) << endl;              // true
}

// # numeric
// <numeric> - Numerical algorithms
// accumulate(), inner_product(), partial_sum(), adjacent_difference(), iota()

// # random 
#include <random>

void cpp_Random() {
  auto engine = default_random_engine{0};
  auto dist = uniform_int_distribution<int>{1,6};

  for(auto i = 0; i < 5; i++) {
    auto dice = dist(engine);
    cout << "dice: " << dice << endl;
  }
}

// # limits
#include <limits>

void cpp_Limits() {
  int maxChar = numeric_limits<char>::max();
  cout << maxChar << endl;
  cout << numeric_limits<char>::is_signed << endl;
  cout << numeric_limits<int>::max() << endl;
}

// # Async Concurrency
// Note - Always use async concurrency for parallel execution. Avoid using thread concurrency unless you are an expert concurrency developer
#include <future>

void cpp_Async() {
  auto sum = [](vector<int> array, int start, int end) {
    auto result = 0;
    for(auto i = start; i < end; i++) {
      result += array[i];
    }
    return result;
  };
  
  vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8 };  // imagine this is very large
  auto t1 = async(sum, data, 0, 4);               // t1 & t2 running parallel
  auto t2 = async(sum, data, 4, 8);               // t1 & t2 running parallel
  auto sum1 = t1.get();                           // wait for t1 to complete
  auto sum2 = t2.get();                           // wait for t2 to complete
  cout << "total: " << sum1+sum2 << endl;         // results 36
}

// # Threads and Locks
#include <thread>

void cpp_Threads() {
  mutex m;
  
  int total = 0;
  auto sum =[&](vector<int> array, int start, int end) {
    for(int i=start; i < end; i++) {
      unique_lock<mutex> lock{m};                 // alternative manual m.lock()
                                                  // and m.unlock() calls
      total += array[i];
    }
  };
  vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8 };  // imagine this is very large
  thread t1([&]() { sum(data, 0, 4); });          // run t1
  thread t2([&]() { sum(data, 4, 8); });          // run t2
  t1.join();                                      // wait for t1
  t2.join();                                      // wait for t2
  cout << "total: " << total << endl;             // results 36
}
// You can use this_thread::sleep_for(milliseconds{100}); to sleep a certain number of milliseconds

// # EVENTS
// Warning - Avoid using your own threads and explicit concurrency, use async concurrency instead

#include <queue>
#include <chrono>

void cpp_Events() {
  queue<string> messages;
  condition_variable cond;
  mutex m;
  
  auto consumer= [&]() {
    while(true) {
      unique_lock<mutex> lock{m};
      cond.wait(lock);
      auto msg = messages.front();
      messages.pop();
      lock.unlock();
      cout << "received: " << msg << endl;
      if (msg == "quit") {
        break;
      }
    }
  };
  
  auto producer = [&]() {
    using namespace std::chrono;
    vector<string> list = { "hello", "world", "quit" };
    for(const auto& msg : list) {
      unique_lock<mutex> lock{m};
      messages.push(msg);
      cond.notify_one();
      m.unlock();
      this_thread::sleep_for(milliseconds{250});
    }
  };
  
  thread prod([&]() { consumer(); });
  thread cons([&]() { producer(); });
  prod.join();
  cons.join();
}

// # Unions
// Unions provide a mechanism to have a value be one of N types. You can think of it as a simple manifestation of algebraic data types
// Note - This is likely to be replaced by use of C++ 17 std::variant or boost::dynamic / folly::dynamic.
//
// Warning - Do not used unions directly. Union use should be wrapped in a helper class with type discriminators
// Warning - Always use pointers for non-scalar values included in unions. You cannot use object values since the size of the union would be the largest possible size of objects as well as ambiguity in which destructor to call.

// # Compile Time Execution
// C++ provides powerful compile time constructs.
// - constexpr - evaluate at compile time, place function in read only memory
// - static_assert(sizeof(int) == 4, "int should be 4 bytes"); - compile time assert
// - template classes and functions provide advanced compile time expansion of code. These can be also exploited to provide powerful template meta programming techniques

// # Additional References
// - Folly: Facebook has a strong C++ heritage and contribution. Folly is an open source library implemented and is in heavy use within the company. Folly includes string improvements, dynamic values, and much more!
// - MSDN: Microsoft has invested heavily (and continues to play a leading role) in the evolution of modern C++. MSDN provides some good guides and references on C++ development
// - cppreference: Perhaps the defacto standard (and most likely Google hit) for reference information


int main(int argc, const char* argv[]) {
    cout << "Hello World!\n";

    cout << isEven(12) << endl;

    var_and_scope();

    references();

    loops();

    _struct();

    cpp_EnumClass();

    cpp_NamespaceExplict();
    cpp_NamespaceImplict();

    try {
        cpp_ExceptionsRethrow();
    }
    catch(const std::exception &e) {
        cout << "type: " << typeid(e).name() << endl
             << "what: " << e.what() << endl;
    }
    // catch(...) {
    //     cout << "NOOP" << endl;
    // }

    cpp_Methods();

    cpp_StaticMethods();

    cpp_ClassContainment();

    cpp_Destructors();

    cpp_Inheritance();

    cpp_Strings();

    cpp_Vectors();

    cpp_Iterators();

    cpp_Arrays();

    cpp_Lambdas();

    cpp_FindWithIterators();

    cpp_InitializerLists();

    cpp_ExplicitConstructors();

    cpp_Using();

    cpp_UniquePointers();

    cpp_DynamicCast();

    cpp_SharedPointers();

    cpp_Regex();

    cpp_RegexIterators();

    cpp_List();

    cpp_Map();

    cpp_Algorithms();

    cpp_Time();

    cpp_Math();

    cpp_Random();

    cpp_Limits();

    cpp_Async();

    cpp_Events();
}
