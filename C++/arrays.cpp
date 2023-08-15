#include<iostream>
using namespace std;
int main()
{
    int marks[4]={98,89,87,80};
    marks[1]=99;
    for(int i=0;i<4;i++)
    {
        cout<<marks[i]<<endl;
    }
    return 0;
}   