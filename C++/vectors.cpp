#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> vec1;
    vector<int> vec2;
    
    vec1.push_back(10);
    vec1.push_back(20);
    cout<<"Vector 1 Contains:"<<endl;
    cout<<vec1.at(0)<<endl;
    cout<<vec1.at(1)<<endl;
    cout<<"/nSize of Vector 1 is: "<<vec1.size()<<"\n"<<endl;

    vec2.push_back(100);
    vec2.push_back(200);
    cout<<"Vector 2 Contains:"<<endl;
    cout<<vec2.at(0)<<endl;
    cout<<vec2.at(1)<<endl;
    cout<<"Size of Vector 2 is: "<<vec2.size()<<"\n"<<endl;

    vector<vector<int> > vec2d;

    vec2d.push_back(vec1);
    vec2d.push_back(vec2);
    cout<<"2D Vector Contains: "<<endl;
    cout<<vec2d.at(0).at(0)<<" "<<vec2d.at(0).at(1)<<endl;
    cout<<vec2d.at(1).at(0)<<" "<<vec2d.at(1).at(1)<<"\n"<<endl;

    vec1.at(0)=1000;
    cout<<"Now Vector 1 Contains:"<<endl;
    cout<<vec1.at(0)<<endl;
    cout<<vec1.at(1)<<"\n"<<endl;

    vec2d.push_back(vec1);
    vec2d.push_back(vec2);
    cout<<vec2d.at(0).at(0)<<" "<<vec2d.at(0).at(1)<<endl; // The value at (0,0) does not change because when we add element to a vector we actually made copy of what we are inserting 
    cout<<vec2d.at(1).at(0)<<" "<<vec2d.at(1).at(1)<<endl;

    return 0;
}