#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> v;
    v.push_back("a");
    v.emplace_back();
    for (const auto& s : v) {
        cout << s << endl;
    }
    cout << v.size() << endl;
}
