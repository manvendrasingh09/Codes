#include <iostream>
#include <thread>
#include <semaphore.h>

sem_t semaphore;

void criticalSection()
{
    sem_wait(&semaphore);
    // Critical section code
    std::cout << "Executing critical section..." << std::endl;
    sem_post(&semaphore);
}

int main()
{
    sem_init(&semaphore, 0, 1);

    std::thread t1(criticalSection);
    std::thread t2(criticalSection);

    t1.join();
    t2.join();

    sem_destroy(&semaphore);

    return 0;
}
