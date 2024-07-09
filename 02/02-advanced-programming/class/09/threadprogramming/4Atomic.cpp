#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>

using namespace std;

// int number = 0;
// atomic keyword will solve the number not reaching desired value.
// atomic<int> number = 0;
void counter(atomic<int> &number)
{
    for (int i = 0; i < 1000000; i++)
    {
        number++;
    }
}

int main()
{

    atomic<int> number = 0;
    thread t1{counter, ref(number)};
    thread t2{counter, ref(number)};
    // why this will show 0?
    cout << number << endl;
    t1.join();
    t2.join();
    // this will not show excepted number
    cout << number;
}