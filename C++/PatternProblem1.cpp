//Rectangular Pattern with m rows and n columns
#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter Rows and Columns: ";
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}