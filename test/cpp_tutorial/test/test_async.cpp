#include <iostream>
#include <future>

using namespace std;

int factorial(std::future<int>& f) {
    int n = f.get();

    int res = 1;
    for (int i = n; i > 1; i--)
        res *= i;
    return res;
}

int main() {
    int x;

    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::future<int> fu = std::async(std::launch::async, factorial, std::ref(f));

    std::this_thread::sleep_for(chrono::milliseconds(20));
    p.set_value(4);

    x = fu.get();
    cout << x;
}
