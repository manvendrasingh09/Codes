//Subset Sum
#include <iostream>
#include <vector>
using namespace std;
void subset (int a[] , int sum, int tmpsum, int p, int size, bool & found, int b[], int c)
{
    if (sum == tmpsum)
        found = true;
    for (int i = p; i < size; i++)
    {
        if (tmpsum + a[i] <= sum)
        {
            b[c++] = a[i];
            tmpsum+= a[i];
            subset (a, sum, tmpsum, i + 1, size, found, b, c);
            b[c--] = a[i];
            tmpsum-= a[i];
        }
    }
    for (int i = 0; i < c; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}
int main(void)
{
    int n, sum;
    bool found = false;
    cin >> n;
    int *arr = new int[n], *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> sum;
    subset (arr, sum, 0, 0, n, found, b, 0);
    if (found)
        cout << "Subset with the given sum found: " << sum << endl;
    else
        cout << "No required subset found" << endl;
    return 0;
}