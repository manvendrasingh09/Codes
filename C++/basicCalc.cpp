#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter two Numbers: ";
    cin>>a>>b;
    char op;
    cout<<"Enter the Operator: ";
    cin>>op;
    switch(op)
    {
        case '+':
        cout<<a+b;
        break;
        case '-':
        cout<<a-b;
        break;
        case '*':
        cout<<a*b;
        break;
        case '/':
        cout<<a/b;
        break;
        default:
        cout<<"Enter a valid operator";
        break;
    }
    return 0;
}