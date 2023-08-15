#include<iostream>
using namespace std;
int main()
{
    int n;
    int sum=0;
    cout<<"Enter the Number: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        sum=sum+i;
    }
    cout<<"Sum of Number upto "<<n<<" is "<<sum;
    return 0;
}