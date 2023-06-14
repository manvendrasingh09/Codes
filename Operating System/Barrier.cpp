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
        int threadIndex = --count;

        if (threadIndex == 0) {
            std::cout << "All threads reached the barrier." << std::endl;
            generation++;
            count = totalThreads;
            cv.notify_all();
        } else {
            std::cout << "Thread " << std::this_thread::get_id() << " reached the barrier." << std::endl;
            cv.wait(lock, [this, gen] { return gen != generation; });
        }
        std::cout << "Thread " << std::this_thread::get_id() << " passed the barrier." << std::endl;
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
    std::cout << "Thread " << std::this_thread::get_id() << " started." << std::endl;

    // Perform some work before reaching the barrier
    std::this_thread::sleep_for(std::chrono::seconds(2));

    barrier.wait();

    // Critical section code
    std::cout << "Thread " << std::this_thread::get_id() << " executing critical section..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Perform some work after leaving the barrier
    std::cout << "Thread " << std::this_thread::get_id() << " finished." << std::endl;
}

int main()
{
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);

    t1.join();
    t2.join();

    return 0;
}
