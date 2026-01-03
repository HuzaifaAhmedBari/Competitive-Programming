#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int total = n;
    int count2=0,count3=0;
    if(n==1)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    while(n!=1)
    {
        if(n%3==0)
        {
            n/=3;
        }
        else if(n%2==0)
        {
            n/=2;
        }
        else if(n!=1)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}