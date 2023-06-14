#include <bits/stdc++.h>
using namespace std;
void printMaxActivities(int s[], int f[], int index[], int n)
{
    int i, j;
    i = 0;
    cout << i << " ";
    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            cout << index[j] << " ";
            i = j;
        }
    }
}
void swapping(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
void bubbleSort(int *f, int *s, int *index, int size)
{
    for (int i = 0; i < size; i++)
    {
        int swaps = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (f[j] > f[j + 1])
            {
                swapping(f[j], f[j + 1]);
                swapping(s[j], s[j + 1]);
                swapping(index[j], index[j + 1]);
                swaps = 1;
            }
        }
        if (!swaps)
            break;
    }
}
int main()
{
    int n, z;
    cin >> n;
    int s[n];
    int index[n];
    for (z = 0; z < n; z++)
    {
        cin >> s[z];
        index[z] = z;
    }
    int f[n];
    for (z = 0; z < n; z++)
    {
        cin >> f[z];
    }
    bubbleSort(f, s, index, n);
    printMaxActivities(s, f, index, n);
    return 0;
}