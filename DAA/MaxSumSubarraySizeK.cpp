// Max Sum Subarray of size K
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int array[a];
    for (int i = 0; i < a; i++)
    {
        cin >> array[i];
    }
    int maxsum = 0;
    for (int i = 0; i < a - b + 1; i++)
    {
        int sum = 0;
        for (int j = i; j < i + b; j++)
        {
            sum += array[j];
        }
        maxsum = max(maxsum, sum);
    }
    cout << maxsum << endl;
    return 0;
}