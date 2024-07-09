#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    atomic<int> count = 0;
    const int ITERATIONS = 1e6;
    thread t1([&count]() {
        for (int i = 0; i < ITERATIONS; i++) {
            ++count;
            // std::cout << count << "A" << endl;
        }
        });

    thread t2([&count]() {
        for (int i = 0; i < ITERATIONS; i++) {
            ++count;
            // std::cout << count << "B" << endl;
        }
        });

    t1.join();
    t2.join();

    std::cout << count << endl;

    return 0;
}