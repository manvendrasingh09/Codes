// Fractional Knapsack Problem
#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swap(float &a, float &b)
{
    float temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int n;
    cin >> n;
    int w[n];
    int profit[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    int knapsack;
    cin >> knapsack;
    float profit_w[n];
    for (int i = 0; i < n; i++)
    {
        profit_w[i] = (float)profit[i] / (float)w[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (profit_w[j] < profit_w[j + 1])
            {
                swap(profit_w[j], profit_w[j + 1]);
                swap(w[j], w[j + 1]);
                swap(profit[j], profit[j + 1]);
            }
        }
    }
    float totalprofit = 0;
    for (int i = 0; i < n; i++)
    {
        if (w[i] <= knapsack)
        {
            knapsack = knapsack - w[i];
            totalprofit += profit[i];
            cout << w[i] << " " << profit[i] << "\n";
        }
        else if (w[i] > knapsack & knapsack != 0)
        {
            float p;
            p = ((float)(knapsack) / (float)(w[i])) * profit[i];
            totalprofit = totalprofit + p;
            cout << knapsack << " " << p << "\n";
            knapsack = 0;
        }
    }
    printf("Total Profit:%d", (int)totalprofit);
    return 0;
}