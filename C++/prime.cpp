#include<iostream>
using namespace std;
int main()
{
    int i,n;
    cout<<"Enter the Number:";
    cin>>n;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            cout<<n<<" is not a Prime Number";
            break;
        }
    }
    if(i==n)
    {
        cout<<n<<" is a Prime Number";
    }
    
    return 0;
}