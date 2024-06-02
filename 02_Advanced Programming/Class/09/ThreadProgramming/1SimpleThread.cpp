#include <iostream>
#include <thread>

using namespace std;

void hello() {
    for (int i = 0; i < 10; i++) {
        cout << "hello" << endl;
    }
}

void world() {
    for (int i = 0; i < 10; i++) {
        cout << "world" << endl;
    }
}

void print(string s) {
    for (int i = 0; i < 10; i++) {
        cout << s << endl;
    }
}

int main() {
    // using hello and world functions work in sync
    thread t1{hello};
    thread t2{world};
    t1.join();
    t2.join();

    // // will pass arguments like this
    // thread t3{print, "hello"};
    // t3.join();
}