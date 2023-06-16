#include <stdio.h>
#include <windows.h>

DWORD WINAPI ThreadFunc(LPVOID lpParam) {
    int threadId = *(int*)lpParam;
    printf("Thread %d is processing the image.\n", threadId);
    // Perform image processing tasks
    return 0;
}

int main() {
    const int numThreads = 3;
    HANDLE threads[numThreads];
    int threadIds[numThreads];

    for (int i = 0; i < numThreads; i++) {
        threadIds[i] = i + 1;
        threads[i] = CreateThread(NULL, 0, ThreadFunc, &(threadIds[i]), 0, NULL);
    }

    WaitForMultipleObjects(numThreads, threads, TRUE, INFINITE);

    for (int i = 0; i < numThreads; i++) {
        CloseHandle(threads[i]);
    }

    return 0;
}
