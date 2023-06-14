// DFA to Epsilon NFA

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
void printNFA(vector<vector<vector<int>>> nfaTable)
{
    cout << " STATE/INPUT |";
    char inputChar = 'a';
    for (int i = 0; i < nfaTable[0].size() - 1; i++)
    {
        cout << " " << inputChar++ << " |";
    }
    cout << " ^ " << endl
        << endl;
    for (int i = 0; i < nfaTable.size(); i++)
    {
        cout << " " << i << " ";
        for (int j = 0; j < nfaTable[i].size(); j++)
        {
            cout << " | ";
            for (int k = 0; k < nfaTable[i][j].size(); k++)
            {
                cout << nfaTable[i][j][k] << " ";
            }
        }
        cout << endl;
    }
}
void printDFA(vector<vector<int>> dfaStates, vector<vector<vector<int>>> dfaTable)
{
    cout << " STATE/INPUT ";
    char inputChar = 'a';
    for (int i = 0; i < dfaTable[0].size(); i++)
    {
        cout << "| " << inputChar++ << " ";
    }
    cout << endl;
    for (int i = 0; i < dfaStates.size(); i++)
    {
        cout << "{ ";
        for (int h = 0; h < dfaStates[i].size(); h++)
            cout << dfaStates[i][h] << " ";
        if (dfaStates[i].empty())
        {
            cout << "^ ";
        }
        cout << "} ";
        for (int j = 0; j < dfaTable[i].size(); j++)
        {
            cout << " | ";
            for (int k = 0; k < dfaTable[i][j].size(); k++)
            {
                cout << dfaTable[i][j][k] << " ";
            }
            if (dfaTable[i][j].empty())
            {
                cout << "^ ";
            }
        }
        cout << endl;
    }
}
vector<int> getClosure(int state, vector<vector<vector<int>>> nfaTable)
{
    vector<int> closureSet;
    queue<int> queue;
    closureSet.push_back(state);
    int inputSize = nfaTable[state][nfaTable[state].size() - 1].size();
    for (int i = 0; i < inputSize; i++)
    {
        closureSet.push_back(nfaTable[state][nfaTable[state].size() - 1][i]);
        queue.push(closureSet[i]);
    }
    while (!queue.empty())
    {
        int front = queue.front();
        queue.pop();
        if (!nfaTable[front][nfaTable[front].size() - 1].empty())
        {
            int size = nfaTable[front][nfaTable[front].size() - 1].size();
            for (int i = 0; i < size; i++)
            {
                int nextState = nfaTable[front][nfaTable[front].size() - 1][i];
                if (find(closureSet.begin(), closureSet.end(), nextState) == closureSet.end())
                {
                    closureSet.push_back(nextState);
                    queue.push(nextState);
                }
            }
        }
    }
    return closureSet;
}
int main()
{
    int numStates, alphabetSize;
    cout << "Enter the total number of states in NFA: ";
    cin >> numStates;
    cout << "Enter the number of elements in the alphabet: ";
    cin >> alphabetSize;
    vector<vector<vector<int>>> nfaTable;
    for (int i = 0; i < numStates; i++)
    {
        cout << "For state " << i << endl;
        vector<vector<int>> transitions;
        char inputChar = 'a';
        int nextState, numTransitions;
        for (int j = 0; j < alphabetSize; j++)
        {
            vector<int> transitionSet;
            cout << "Enter the number of output states for input " << inputChar++ << " : ";
            cin >> numTransitions;
            cout << "Enter the output states:" << endl;
            for (int k = 0; k < numTransitions; k++)
            {
                cin >> nextState;
                transitionSet.push_back(nextState);
            }
            transitions.push_back(transitionSet);
        }
        vector<int> epsilonTransitionSet;
        cout << "Enter the number of output states for input ^ : ";
        cin >> numTransitions;
        cout << "Enter the output states:" << endl;
        for (int k = 0; k < numTransitions; k++)
        {
            cin >> nextState;
            epsilonTransitionSet.push_back(nextState);
        }
        transitions.push_back(epsilonTransitionSet);
        nfaTable.push_back(transitions);
    }
    printNFA(nfaTable);
    cout << endl
        << "-------TRANSITION TABLE OF DFA-------" << endl;
    vector<vector<vector<int>>> dfaTable;
    vector<vector<int>> dfaStates;
    dfaStates.push_back(getClosure(0, nfaTable));
    queue<vector<int>> queue;
    queue.push(dfaStates[0]);
    while (!queue.empty())
    {
        vector<int> front = queue.front();
        queue.pop();
        vector<vector<int>> transitions;
        for (int i = 0; i < alphabetSize; i++)
        {
            vector<int> transitionSet;
            set<int> stateSet;
            for (int j = 0; j < front.size(); j++)
            {
                for (int k = 0; k < nfaTable[front[j]][i].size(); k++)
                {
                    vector<int> closureSet = getClosure(nfaTable[front[j]][i][k], nfaTable);
                    for (int h = 0; h < closureSet.size(); h++)
                    {
                        if (stateSet.find(closureSet[h]) == stateSet.end())
                            stateSet.insert(closureSet[h]);
                    }
                }
            }
            for (set<int>::iterator iter = stateSet.begin(); iter != stateSet.end(); iter++)
                transitionSet.push_back(*iter);
            transitions.push_back(transitionSet);
            if (find(dfaStates.begin(), dfaStates.end(), transitionSet) == dfaStates.end())
            {
                dfaStates.push_back(transitionSet);
                queue.push(transitionSet);
            }
        }
        dfaTable.push_back(transitions);
    }
    printDFA(dfaStates, dfaTable);
    return 0;
}