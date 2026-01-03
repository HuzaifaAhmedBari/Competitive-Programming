#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    n+=4;
    if(n==0)
        cout<<1<<endl;
    if(n%4==0)
        cout<<6<<endl;
    else if(n%4-1==0)
        cout<<8<<endl;
    else if(n%4-2==0)
        cout<<4<<endl;
    else
        cout<<2<<endl;
}