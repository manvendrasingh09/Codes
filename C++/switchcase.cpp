#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"Enter the age: ";
    cin>>age;
    switch (age)
    {
    case 18:
        cout<<"Your age is 18";
        break;
    case 22:
        cout<<"Your age is 22";
        break;
    case 30:
        cout<<"Your age is 18";
        break;
    default:
        cout<<"Enter a valid age";
        break;
    }
}