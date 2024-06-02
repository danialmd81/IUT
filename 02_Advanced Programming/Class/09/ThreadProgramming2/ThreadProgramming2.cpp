#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <shared_mutex>
#include <string>
#include <thread>

using namespace std;
// multiple readers and one writer code with shared_lock
string file = "Original content."; // our shared resource
mutex output_mutex;                // lock cout
shared_mutex file_mutex;           // shared_lock
void read_content(int id)          // readers
{
    string content; // the content representing the file we wish to read
    {
        shared_lock lock(
            file_mutex, defer_lock); // shared_lock for readers so other readers
        // can join while a reader is in process
        lock.lock();                 // defer_lock keyword does not lock the content; we lock
        // the content here
        content = file;              // we copy the content we wanted and unlock it once we
        // are out of the defined scope
    }
    output_mutex.lock(); // cout lock
    cout << "Contents read by reader #" << id << ": " << content << '\n';
    output_mutex.unlock();
}
void write_content() // writers lock
{
    {
        unique_lock file_lock(
            file_mutex); // unique lock to not allow any readers or writers
        // access the source
        file = "New content";
    }
    lock_guard output_lock(output_mutex); // cout lock
    cout << "New content saved.\n";
}
queue<string> mq;        // a queue to use conditional variable with
mutex mx;                // control the sources access
condition_variable cond; // conditional variable to signal the reader that there
// is a file in the queue
void send()
{ // sender who puts data in the queue
    while (true)
    {
        string m;
        cin >> m;
        mx.lock();
        mq.push(m);
        cout << "message was pushed on the queue" << endl;
        mx.unlock();
        cond.notify_one(); // notifying readers that there is a message on the
        // queue
    }
}
void receiver()
{
    while (true)
    {

        unique_lock lock(mx); // locking queue(our source)
        cond.wait(lock, []()
            { return !mq.empty(); }); // this will wait for the condition to notify it. will also unlock
        // the lock so others can use it
        string f = mq.front();
        mq.pop();
        lock.unlock(); // unlocking the lock used on queue
        //
        // if there is several codes here, it makes sense to use 2 locks one for
        // queue and one for cout
        //
        mx.lock(); // a specific lock for cout
        cout << "the message was : " << f << endl;
        mx.unlock();
    }
}
int main()
{
    // cout << "Two readers reading from file.\n" << "A writer competes with
    // them.\n"; thread reader1{ read_content, 1 }; thread reader2{
    // read_content, 2 }; thread writer{ write_content }; reader1.join();
    // reader2.join();
    // writer.join();
    // cout << "The first few operations to file are done.\n";
    // reader1 = thread{ read_content, 3 };
    // reader1.join();
    thread t1{ send };
    thread t2{ receiver };
    t1.join();
    t2.join();
}