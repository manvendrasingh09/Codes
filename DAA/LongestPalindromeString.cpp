// Longest Palindrome in a String
#include <iostream>
#include <string>
using namespace std;
string longestPalindrome(string s)
{
    int n = s.length();
    int maxLen = 0;
    string longest = "";
    bool table[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            table[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        table[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            table[i][i + 1] = true;
        }
    }
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && s[i] == s[j])
            {
                table[i][j] = true;
                if (k > maxLen)
                {
                    longest = s.substr(i, k);
                    maxLen = k;
                }
            }
        }
    }
    int lastLength = 2;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            string sub = s.substr(j, i);
            if (sub == string(sub.rbegin(), sub.rend()))
            {
                if (i != lastLength)
                {
                    cout << sub << endl;
                    lastLength = i;
                }
                break;
            }
        }
    }
    if (maxLen > 2)
    {
        cout << "Longest Palindrome is " << longest << endl;
    }
    else
    {
        cout << "Longest Palindrome is of length 2 or less" << endl;
    }
    return longest;
}
int main()
{
    string s;
    cin >> s;
    longestPalindrome(s);
    return 0;
}