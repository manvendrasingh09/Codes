#include<iostream>
using namespace std;
int main()
{
    int marks[4]={98,89,87,80};
    marks[1]=99;
    cout<<"The values in arrays are: ";
    cout<<"[";
    for(int i=0;i<4;i++)
    {
        cout<<marks[i]<<" ";
    }
    cout<<"]"<<endl;
    //Pointer and Array
    int* p=marks; //In array no need to write &marks
    cout<<"The address of marks[0] is: "<<p<<endl;
    cout<<"The value of marks[0] is: "<<*p<<endl;
    cout<<"The address of marks[1] is: "<<p+1<<endl;
    cout<<"The value of marks[1] is: "<<*(p+1)<<endl;
    cout<<"The address of marks[2] is: "<<p+2<<endl;
    cout<<"The value of marks[2] is: "<<*(p+2)<<endl;
    cout<<"The address of marks[3] is: "<<p+3<<endl;
    cout<<"The value of marks[3] is: "<<*(p+3)<<endl;
    return 0;
}   