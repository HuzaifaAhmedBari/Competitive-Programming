#include<iostream>
using namespace std;
int main()
{
    int i,j,t;
    cin>>i>>j>>t;
    if(i<=j && i<=t)
        cout<<i;
    else if(j<=i && j<=t)
        cout<<j;
    else
        cout<<t;
}