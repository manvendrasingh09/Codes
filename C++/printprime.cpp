//Print all prime number b/w two numbers given by a user
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter the two Numbers: ";
    cin>>a>>b;
    for (int num=a;num<=b;num++)
    {
        int i;
        for(i=2;i<num;i++)
        {
            if(num%i==0)
            {
                break;
            }
        }
        if(i==num)
        {
            cout<<num<<" ";
        }
    }
    return 0;
}