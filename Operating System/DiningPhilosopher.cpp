#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

const int NUM_PHILOSOPHERS = 5;

class DiningPhilosophers {
private:
    mutex mutexes[NUM_PHILOSOPHERS];
    condition_variable cv[NUM_PHILOSOPHERS];
    enum class State { THINKING, HUNGRY, EATING };
    State states[NUM_PHILOSOPHERS];

public:
    DiningPhilosophers() {
        for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
            states[i] = State::THINKING;
        }
    }

    void takeForks(int philosopherId) {
        mutex lock(mutexes[philosopherId]);
        states[philosopherId] = State::HUNGRY;
        test(philosopherId);
        if (states[philosopherId] != State::EATING) {
            cv[philosopherId].wait(lock);
        }
    }

    void putForks(int philosopherId) {
        mutex lock(mutexes[philosopherId]);
        states[philosopherId] = State::THINKING;
        test((philosopherId + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS);
        test((philosopherId + 1) % NUM_PHILOSOPHERS);
    }

    void test(int philosopherId) {
        if (states[philosopherId] == State::HUNGRY &&
            states[(philosopherId + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS] != State::EATING &&
            states[(philosopherId + 1) % NUM_PHILOSOPHERS] != State::EATING) {
            states[philosopherId] = State::EATING;
            cv[philosopherId].notify_all();
        }
    }
};

void philosopher(DiningPhilosophers& dp, int philosopherId) {
    while (true) {
        // Thinking
        cout << "Philosopher " << philosopherId << " is thinking." << endl;
        this_thread::sleep_for(chrono::seconds(1));

        // Take forks
        dp.takeForks(philosopherId);
        cout << "Philosopher " << philosopherId << " is eating." << endl;
        this_thread::sleep_for(chrono::seconds(2));

        // Put forks
        dp.putForks(philosopherId);
    }
}

int main() {
    DiningPhilosophers dp;
    thread philosophers[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i] = thread(philosopher, ref(dp), i);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i].join();
    }

    return 0;
}
