#include <iostream>
#include <string>
using namespace std;
void Subsequence(const string &str, const string &subse, int index)
{
    if (index == str.length())
    {
        if (!subse.empty() && subse.length() > 1)
        {
            cout << subse << " ";
        }
        return;
    }
    Subsequence(str, subse + str[index], index + 1);
    Subsequence(str, subse, index + 1);
}
void spec(const string &str)
{
    cout << "Prefix: ";
    for (int i = 0; i < str.length(); i++)
    {
        cout << str.substr(0, i + 1) << " ";
    }
    cout << "\nProper Prefix: ";
    for (int i = 0; i < str.length() - 1; i++)
    {
        cout << str.substr(0, i + 1) << " ";
    }
    cout << "\nSuffix: ";
    for (int i = 0; i <= str.length(); i++)
    {
        cout << str.substr(i) << " ";
    }
    cout << "\nProper Suffix: ";
    for (int i = 1; i <= str.length(); i++)
    {
        cout << str.substr(i) << " ";
    }
    cout << "\nSubstring: ";
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 1; j <= str.length() - i; j++)
        {
            cout << str.substr(i, j) << " ";
        }
    }
    cout << "\nSubsequence: ";
    Subsequence(str, "", 0);
}
int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    spec(str);
    return 0;
}