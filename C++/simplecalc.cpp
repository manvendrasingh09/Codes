#include<iostream>
using namespace std;
int main()
{
    int a,b,c,result;
    cout<<"Enter the first number: ";
    cin>>a;
    cout<<"Enter the second number: ";
    cin>>b;
    cout<<"(1 for ADD, 2 for Substract, 3 for Multiply, 4 for Division)"<<endl;
    cout<<"Enter the Operation:"<<endl;
    cin>>c;
    if(c==1)
    {
        result=a+b;
        cout<<result;
    }
    else if (c==2)
    {
        result=a-b;
        cout<<result;
    }
    else if (c==3)
    {
        result=a*b;
        cout<<result;
    }
    else if (c==4)
    {
        result=a/b;
        cout<<result;
    }
    return 0;
}