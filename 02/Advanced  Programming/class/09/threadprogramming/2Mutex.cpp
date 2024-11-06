#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex m2;
void hello() {
    // using mutex to lock the shared resource
    m2.lock();
    // between hello and world function. what is the shared resource here?
    for (int i = 0; i < 10; i++) {
        cout << "hello" << endl;
    }
    m2.unlock();
}
mutex m3;
void world() {
    scoped_lock lock{m2};
    // what will happen if we lock inside the for loop?
    m3.lock();
    for (int i = 0; i < 10; i++) {
        cout << "world" << endl;
    }
    m2.unlock();
}

mutex mute;
void print(string s) {
    scoped_lock lock{mute};
    for (int i = 0; i < 10; i++) {
        cout << s << endl;
    }
}

int main() {
    // we solved the sync problem with mutex
    thread t1{print, "hello"};
    thread t2{print, "welcome"};
    t1.join();
    t2.join();

    // // using hello and world functions with  mutex or shared_lock to prevent
    // // resource sharing
    // thread t3{hello};
    // thread t4{world};
    // t3.join();
    // t4.join();
}
