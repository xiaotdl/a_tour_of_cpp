#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


std::mutex mu;


void shared_print(string msg, int id) {
    std::lock_guard<std::mutex> guard(mu); // RAII
    // mu.lock();
    cout << msg << id << endl;
    // mu.unlock();
}

void f1() {
    for (int i = 0; i < 100; ++i) {
        shared_print("from t1: ", i);
    }
}

int main() {
    thread t1(f1);
    for (int i = 0; i > -100; --i) {
        shared_print("from main: ", i);
    }
    t1.join();

    // t1.detach(); // t1 becomes daemon process
    cout << thread::hardware_concurrency();
}
