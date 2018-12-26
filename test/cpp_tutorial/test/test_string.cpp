#include <iostream>
#include <string>

using namespace std;

// string mystring = "This is a string";
// string mystring ("This is a string");
// string mystring {"This is a string"};

int main() {
    string s;
    cout << s;
    s = "hello world!";
    cout << s;

    char* charPtr = "abc";
    
    cout << 
        "hello"
        " world"
        "!\n";

    string name = "bob";
    cout << "My name is " + name + "\n";
    // `endl` insert an '\n' and also flush the stream buffer 
    cout << "My name is " << name << endl;
}
