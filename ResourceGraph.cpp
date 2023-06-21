#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class DeadlockDetection {
private:
    int numProcesses;
    int numResources;
    vector<vector<int>> allocation;
    vector<vector<int>> request;
    vector<bool> visited;
    vector<bool> safeSequence;

public:
    DeadlockDetection(int nProcesses, int nResources) : numProcesses(nProcesses), numResources(nResources),
                                                        allocation(nProcesses, vector<int>(nResources)),
                                                        request(nProcesses, vector<int>(nResources)),
                                                        visited(nProcesses, false),
                                                        safeSequence(nProcesses, false) {}

    void setAllocationMatrix(const vector<vector<int>>& allocationMatrix) {
        allocation = allocationMatrix;
    }

    void setRequestMatrix(const vector<vector<int>>& requestMatrix) {
        request = requestMatrix;
    }

    void detectDeadlock() {
        vector<bool> isAvailable(numResources, true);
        vector<bool> isAllocated(numProcesses, false);

        for (int i = 0; i < numProcesses; ++i) {
            vector<int> available(numResources, 0);
            vector<int> allocated(numResources, 0);

            for (int j = 0; j < numResources; ++j) {
                available[j] = isAvailable[j] ? allocation[i][j] : 0;
                allocated[j] = isAllocated[i] ? allocation[i][j] : 0;
            }

            if (isLessThanOrEqual(available, request[i])) {
                isAvailable = logicalOr(isAvailable, allocated);
                isAllocated[i] = true;
                visited[i] = true;
                i = -1;  // Reset to start from the beginning
            }
        }

        queue<int> safeQueue;

        for (int i = 0; i < numProcesses; ++i) {
            if (visited[i]) {
                safeQueue.push(i);
            }
        }

        while (!safeQueue.empty()) {
            int process = safeQueue.front();
            safeQueue.pop();
            safeSequence[process] = true;
        }

        cout << "Safe sequence: ";
        for (int i = 0; i < numProcesses; ++i) {
            if (safeSequence[i]) {
                cout << i << " ";
            }
        }
        cout << endl;

        bool deadlockDetected = false;
        for (int i = 0; i < numProcesses; ++i) {
            if (!visited[i]) {
                cout << "Deadlock detected! Process " << i << " is involved." << endl;
                deadlockDetected = true;
            }
        }

        if (!deadlockDetected) {
            cout << "No deadlock detected." << endl;
        }
    }

private:
    bool isLessThanOrEqual(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] > b[i]) {
                return false;
            }
        }
        return true;
    }

    vector<bool> logicalOr(const vector<bool>& a, const vector<int>& b) {
        vector<bool> result(a.size());

        for (int i = 0; i < a.size(); ++i) {
            result[i] = a[i] || (b[i] > 0);
        }

        return result;
    }
};

int main() {
    DeadlockDetection dd(5, 3);

    vector<vector<int>> allocationMatrix = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    vector<vector<int>> requestMatrix = {
        {0, 0, 0},
        {2, 0, 2},
        {0, 0, 0},
        {1, 0, 0},
        {0, 0, 2}
    };

    dd.setAllocationMatrix(allocationMatrix);
    dd.setRequestMatrix(requestMatrix);
    dd.detectDeadlock();

    return 0;
}
