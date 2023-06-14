#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore {
public:
    Semaphore(int count) : count_(count) {}

    void Wait() {
        unique_lock<mutex> lock(mutex_);
        while (count_ == 0) {
            condition_.wait(lock);
        }
        count_--;
    }

    void Signal() {
        unique_lock<mutex> lock(mutex_);
        count_++;
        condition_.notify_one();
    }

private:
    int count_;
    mutex mutex_;
    condition_variable condition_;
};

Semaphore semaphore(1);

void WorkerThread(int id) {
    semaphore.Wait();

    // Critical section
    cout << "Thread " << id << " is in the critical section." << endl;

    semaphore.Signal();

    // Remaining section
    cout << "Thread " << id << " is in the remaining section." << endl;
}

int main() {
    thread t1(WorkerThread, 1);
    thread t2(WorkerThread, 2);

    t1.join();
    t2.join();

    return 0;
}
