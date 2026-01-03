#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int a,b;
    int t;
    cin>>t;
    long long int d= 1000000007;
    while(t--)
    {
        cin>>a>>b;
        if(a==0 && b==0)
        {
            cout<<1<<endl;
            continue;
        }
        else if(a==0 && b!=0)
        {
            cout<<0<<endl;
            continue;
        }
        else if(a!=0 && b==0)
        {
            cout<<1<<endl;
            continue;
        }
        long long int ans=a;
        long long int result =a;
        for(long long int i=1;i<b;i++)
        {
            result = (result*ans)%d;
        }
        cout<<result<<endl;
    }
}