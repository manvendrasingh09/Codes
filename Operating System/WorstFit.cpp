#include <iostream>
#include <vector>

using namespace std;

// Function to allocate memory to blocks as per worst fit algorithm
void worstFit(vector<int>& blockSize, vector<int>& processSize) {
    int m = blockSize.size();
    int n = processSize.size();

    // Stores block id of the block allocated to a process
    vector<int> allocation(n, -1);

    // Pick each process and find suitable blocks according to its size and assign to it
    for (int i = 0; i < n; i++) {
        // Find the worst fit block for the current process
        int wstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
        }

        // If we could find a block for the current process
        if (wstIdx != -1) {
            // Allocate block j to process i
            allocation[i] = wstIdx;

            // Reduce available memory in this block
            blockSize[wstIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    int m, n;

    cout << "Enter the number of memory blocks: ";
    cin >> m;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> blockSize(m);
    vector<int> processSize(n);

    cout << "Enter the sizes of memory blocks: ";
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
    }

    cout << "Enter the sizes of processes: ";
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }

    worstFit(blockSize, processSize);

    return 0;
}
