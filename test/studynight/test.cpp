#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

set<string> makeSet() {
    set<string> res;
    res.emplace("1");
    return res;
}

int main() {
   set<string> set_ = makeSet(); 
   cout << set_.size() << endl;
}
