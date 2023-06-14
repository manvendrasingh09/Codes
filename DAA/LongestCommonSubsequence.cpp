// Longest Common Subsequence
#include <iostream>
#include <string>
using namespace std;
int lcs(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[m][n];
}
int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    int length = lcs(str1, str2);
    cout << "Length of LCS is " << length << endl;
    return 0;
}