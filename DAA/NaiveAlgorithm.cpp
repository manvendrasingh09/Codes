// Naive algorithm for Pattern Searching
#include <iostream>
#include <cstring>
using namespace std;
void naivePatternSearch(string mainString, string pattern, int array[], int *index)
{
    int patLen = pattern.size();
    int strLen = mainString.size();
    for (int i = 0; i <= (strLen - patLen); i++)
    {
        int j;
        for (j = 0; j < patLen; j++)
        {
            if (mainString[i + j] != pattern[j])
                break;
        }
        if (j == patLen)
        {
            (*index)++;
            array[(*index)] = i;
        }
    }
}
int main()
{
    string mainString;
    getline(cin, mainString);
    string pattern;
    getline(cin, pattern);
    int locArray[mainString.size()];
    int index = -1;
    naivePatternSearch(mainString, pattern, locArray, &index);
    for (int i = 0; i <= index; i++)
    {
        cout << "Pattern found at index: " << locArray[i] << endl;
    }
}