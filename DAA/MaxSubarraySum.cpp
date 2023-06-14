// Maximum Subarray Sum
#include <iostream>
#include <vector>
using namespace std;
vector<int> Subarray(vector<int> &A, int N, int S)
{
    int l = 0, r = 0;
    int Sum = 0;
    vector<int> result;
    while (r < N)
    {
        Sum += A[r];
        while (Sum >= S)
        {
            if (Sum == S)
            {
                result.push_back(l + 1);
                result.push_back(r + 1);
                return result;
            }
            Sum -= A[l];
            l++;
        }
        r++;
    }
    result.push_back(-1);
    result.push_back(-1);
    return result;
}
int main()
{
    int N, S;
    cin >> N;
    cin >> S;
    vector<int> A(N);
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<int> result = Subarray(A, N, S);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}