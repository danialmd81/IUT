#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
mutex m2;

void hello() {
    // scoped_lock lock{ m2 }; //this will lock the scope and unlock once we are
    // out of scope m2.lock(); // using mutex to lock the shared resource
    // between hello and world function. what is the shared resource here?
    for (int i = 0; i < 10; i++) {
        cout << "hello" << endl;
    }
    // m2.unlock();
}
mutex m3;
void world() {
    // scoped_lock lock{ m2 };
    // m2.lock(); // what will happen if we lock inside the for loop?
    for (int i = 0; i < 10; i++) {
        cout << "world" << endl;
    }
    // m2.unlock();
}
int number = 0;
// atomic<int> number = 0; atomic keyword will solve the number not reaching
// desired value.
void counter() {
    for (int i = 0; i < 1000000; i++) {
        number++;
    }
}

mutex mute;
void print(string s) {
    scoped_lock lock{mute};
    for (int i = 0; i < 10; i++) {
        cout << s << endl;
    }
}
// void sum(int a, int b, int& c) {
//     c = a + b;
// }
bool flag = true; // we want to show that we can use cout and cin in sync
void out() {      // in this function, we wait for the input to get char 'a' to
             // change the flag that is used in main to print cout while flag is
             // true
    char ch;
    while (flag) {
        ch = getchar();
        if (ch == 'a')
            flag = false;
    }
}
int main() {
    // using hello and world functions work in sync
    thread t1{hello};
    thread t2{world};
    t1.join();
    t2.join();
    // // will pass arguments like this
    // thread t1{print, "hello"};
    // t1.join();

    // // we solved the sync problem with mutex
    // thread t1{ print,"hello" };
    // thread t2{ print,"welcome" };
    // t1.join(); t2.join();

    // // using hello and world functions with  mutex or shared_lock to prevent
    // // resource sharing
    // thread t1{hello};
    // thread t2{world};
    // t1.join();
    // t2.join();

    //   thread t1{ counter };
    // thread t2{ counter };
    // cout << number << endl;//why this will show 0?
    // t1.join(); t2.join();
    // cout << number; // this will not show excepted number

    // thread t1{ out };
    // while(flag){//how come flag is changing here but the number was shown 0
    // 	cout << "hello" << endl;
    // }
    // t1.join();
}
