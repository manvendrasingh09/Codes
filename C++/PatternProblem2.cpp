//Hollow Rectangular Pattern
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
            if(i==1||i==m)
            {
                cout<<"*";
            }
            else if(j==1||j==n)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}