#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int temp,flag=0;
    for(int i=1;i<=5;i++)
    {
        cin>>temp;
        flag+=abs(temp-i);
    }
    if(flag==2)
        cout<<"Yes";
    else
        cout<<"No";
}