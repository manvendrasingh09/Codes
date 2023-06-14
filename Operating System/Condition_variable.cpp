#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;

void waitForSignal()
{
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });
    // Critical section code
    cout << "Executing critical section..." << endl;
    //Output message after a delay of 2 seconds, indicating that the condition variable correctly synchronized the two threads
}

void sendSignal()
{
    this_thread::sleep_for(chrono::seconds(2)); // Simulate some work
    {
        lock_guard<mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
}

int main()
{
    thread t1(waitForSignal);
    thread t2(sendSignal);

    t1.join();
    t2.join();

    return 0;
}
