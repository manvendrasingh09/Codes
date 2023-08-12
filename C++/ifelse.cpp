#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"Enter your age: ";
    cin>>age;
    if(age>=18)
    {
        cout<<"Allowed To Vote";
    }
    else
    {
        cout<<"Not Allowed To Vote";
    }
    return 0;
}