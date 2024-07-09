#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>

using namespace std;

int main()
{
    int count = 0;
    const int ITERATIONS = 1e4;

    mutex mtx;

    auto func = [&](char a)
        {
            for (int i = 0; i < ITERATIONS; i++)
            {
                mtx.lock();
                ++count;
                cout << a;
                mtx.unlock();
            }
            cout << endl;
        };

    thread t1(func, 'A');
    thread t2(func, 'B');

    t1.join();
    t2.join();

    cout << count << endl;

    return 0;
}