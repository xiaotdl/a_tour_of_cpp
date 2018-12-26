#include <iostream>
#include <string>
#include <regex>

using namespace std;

string compose(const string& a, const string& b) {
  return a + "@" + b;
}

string name = "Niels Stroustrup";
void m3() {
  string s = name.substr(6,10); // s = "Stroustrup"
  name.replace(0,5,"nicholas"); // name becomes "nicholas Stroustrup"
  name[0] = toupper(name[0]); // name becomes "Nicholas Stroustrup"
}
int main() {
  cout << "Hello World!\n";
  auto addr = compose("dmr","bell−labs.com");
  cout << addr << endl;

  m3();
  cout << name << endl;

  // if ("aaa" == "aaa") {
  if (strcmp("aaa", "aaa")) {
    cout << "eq" << endl;
  }

  // regex pattern(); // U.S. postal code pattern

  cout << regex_match("CA 95050", regex("\\w{2}\\s*\\d{5}(-\\d{4})?")) << endl;
}
