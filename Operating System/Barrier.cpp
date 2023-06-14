#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Barrier {
public:
    explicit Barrier(int numThreads) : totalThreads(numThreads), count(numThreads), generation(0) {}

    void wait()
    {
        std::unique_lock<std::mutex> lock(mutex);
        int gen = generation;

        if (--count == 0) {
            generation++;
            count = totalThreads;
            cv.notify_all();
        } else {
            cv.wait(lock, [this, gen] { return gen != generation; });
        }
    }

private:
    std::mutex mutex;
    std::condition_variable cv;
    int totalThreads;
    int count;
    int generation;
};

Barrier barrier(2);

void threadFunction()
{
    // Perform some work before reaching the barrier

    barrier.wait();

    // Critical section code
    std::cout << "Executing critical section..." << std::endl;

    // Perform some work after leaving the barrier
}

int main()
{
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);

    t1.join();
    t2.join();

    return 0;
}
