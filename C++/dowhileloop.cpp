#include<iostream>
using namespace std;
int main()
{
    int i=1;
    int m;
    cout<<"Enter the number for which you want to print the table: ";
    cin>>m;
    do
    {
        cout<<m<<"*"<<i<<"="<<m*i<<endl;
        i++;
    }while(i<=10);
}